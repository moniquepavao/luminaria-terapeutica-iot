#include "WiFiEsp.h"
#include "PubSubClient.h"

// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7); // RX, TX
#endif

char ssid[] = "<ssid>";      // SSID da rede wifi
char pass[] = "<password>";    // Senha da rede wifi
int status = WL_IDLE_STATUS; // Estado da conexão do wifi

int pushButton = 3; // pino que o PUSH BUTTON está ligado

int ldrPin = A0; // pino que o LDR está ligado
int sensorValue = 0; // variável que guarda o valor do sensor

int led1 = 9; // pino que o LED 1 está ligado
int led2 = 10; // pino que o LED 2 está ligado
int led3 = 11; // pino que o LED 3 está ligado

byte lastButtonState = LOW;
bool turnOn = false;

// Declaração da função para receber as mensagens do tópico
void subscribeReceive(char* topic, byte* payload, unsigned int length);

const char* mqtt_server = "broker.hivemq.com"; // Broker MQTT
 
WiFiEspClient espClient;
PubSubClient mqttClient(espClient);

#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];

int value = 0;
unsigned long lastMsg = 0;

const long reconnectionInterval = 5000;  // interval at which to blink (milliseconds)
unsigned long previousMillis = 0;

void setup() {
  // inicializa a porta serial e configura a taxa de comunicação em 9600 bps (bits por segundo).
  Serial.begin(9600); 
  // initialize serial for ESP module
  Serial1.begin(9600);
  // initialize ESP module
  WiFi.init(&Serial1);

  // Aguarda o boot da placa ESP
  delay(3000);  

  // Verifica o estado do módulo wifi
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  // Conexão com wifi
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
  
  // Configuração de conexão com broker mqtt
  mqttClient.setServer(mqtt_server, 1883);   
 
  if (mqttClient.connect("arduino_lighting")) {
    Serial.println("Connection has been established, well done");
    mqttClient.setCallback(subscribeReceive);
  } 
  else {
    Serial.println("Looks like the server connection failed...");
  }

  pinMode(pushButton, INPUT); // inicializa o PUSH BUTTON como entrada

  pinMode(ldrPin, INPUT); // inicializa o LDR como entrada
  
  pinMode(led1, OUTPUT); // inicializa o LED 1 como saída
  pinMode(led2, OUTPUT); // inicializa o LED 2 como saída
  pinMode(led3, OUTPUT); // inicializa o LED 3 como saída
}

void loop() {

  if (!mqttClient.connected()) {
    reconnect();
  }

  mqttClient.loop();

  /*
      Enquanto a variável turnOn está com o valor false, o programa deve desligar os LEDS. 
      A função pra verificar se o PUSH BUTTON sempre é chamado no final do While.
      Se PUSH BUTTON foi pressionado, o valor é alterado para TRUE, então o programa liga os LEDS, lê o valor do sensor e aplica o brilho proporcional aos LEDS.
  */
  while (!turnOn) {

    digitalWrite(led1, LOW); // desliga o LED 1
    digitalWrite(led2, LOW); // desliga o LED 2
    digitalWrite(led3, LOW); // desliga o LED 3

    checkPushButton();
  }

  sensorValue = analogRead(ldrPin); // lê o valor que o LDR está enviando

  analogWrite(led1, map(sensorValue, 0, 1023, 2, 255)); // Conforme o ambiente escurece o brilho do LED 1 é reduzido
  analogWrite(led2, map(sensorValue, 0, 1023, 2, 255)); // Conforme o ambiente escurece o brilho do LED 2 é reduzido
  analogWrite(led3, map(sensorValue, 0, 1023, 2, 255)); // Conforme o ambiente escurece o brilho do LED 3 é reduzido

  checkPushButton();

  unsigned long now = millis();
  
  if (now - lastMsg > 5000) {
    lastMsg = now;
    ++value;
    
    snprintf (msg, MSG_BUFFER_SIZE, "Valor do LDR #%d", sensorValue);
    Serial.print("Publish message: ");
    Serial.println(msg);
    mqttClient.publish("lighting/general", msg);
  }
}

/*
  Função que verifica se o PUSH BUTTON foi pressionado. Se foi pressionado salva o valor na variável turnOn.
  A função inverte o último valor que foi salvo na variável. 
*/
void checkPushButton() {
  byte buttonState = digitalRead(pushButton); // lê o valor que o PUSH BUTTON está enviando
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {      
      turnOn = !turnOn;

      if (!mqttClient.connected()) {
        reconnect();
      }

      snprintf (msg, MSG_BUFFER_SIZE, "PUSH BUTTON foi pressionado");
      Serial.print("Publish message: ");
      Serial.println(msg);
      mqttClient.publish("lighting/general", msg);
    }
  }
}

void printWifiStatus() {
  // exibe a rede conectada
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // exibe o ip do dispositivo
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void subscribeReceive(char* topic, byte* payload, unsigned int length) {
  // Tópico mqtt que está inscrito
  Serial.print("Topic: ");
  Serial.println(topic);
 
  // Mensagem recebida
  Serial.print("Message: ");
  for(int i = 0; i < length; i ++) {
    Serial.print(char(payload[i]));
  }
 
  Serial.println("");
}

void reconnect() {

  unsigned long currentMillis = millis();

  // Caso não esteja conectado ao broker e já passou 5 seg, reconecta novamente
  if (!mqttClient.connected() && (currentMillis - previousMillis >= reconnectionInterval)) {
    previousMillis = currentMillis;

    Serial.print("Attempting MQTT connection…");
    String clientId = "arduino_lighting";
 
    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("connected");
      mqttClient.publish("lighting/general", "reconnected");
      mqttClient.subscribe("lighting/general");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(mqttClient.state());
    }
  }
}
