# luminaria-terapeutica-IoT
Meu projeto IoT da Universidade Presbiteriana Mackenzie. O projeto foi desenvolvido utiliazando a IDE Arduino e a linguagem nativa do arduino baseada em C++.

## <br> Descrição
O projeto Luminária Terapêutica se propõe a desenvolver um dispositivo acessível e eficaz para combater os efeitos negativos da falta de luz natural, especialmente no inverno.
A luminária utilizará luz azul para regular o ritmo circadiano e melhorar o humor, contribuindo para a saúde mental e física das pessoas., 
combinado com o sensor ECG AD8232 e um buzzer como atuador para alertas.
O desenvolvimento será feito na IDE do Arduino, empregando programação específica para integrar hardware e software, incluindo a comunicação via MQTT 
para transmissão de dados em tempo real.

O projeto Luminária Terapêutica apresenta-se como uma solução, acessível e eficaz para combater os efeitos da falta de luz natural e 
contribuir para a saúde mental e física da sociedade. Conforme o artigo “Influência da luz no sono e no humor” de Gabriela Ferreira (2022),
podemos observar o crescente interesse pela terapia da luz e o potencial da luz azul para melhorar a qualidade de vida das pessoas.

## <br> Instalação da IDE do Arduino
Baixar a IDE do Arduino:

Acesse o site oficial do Arduino.
Navegue até a seção de downloads e escolha a versão da IDE do Arduino compatível com seu sistema operacional (Windows, macOS ou Linux).
Instalar a IDE:

Windows: Execute o instalador baixado e siga as instruções na tela. Certifique-se de instalar todos os drivers necessários durante o processo de instalação.
macOS: Abra o arquivo .zip baixado e arraste o aplicativo Arduino para a pasta "Aplicativos".
Linux: Descompacte o arquivo baixado e execute o script de instalação.
Verificar a Instalação:

Abra a IDE do Arduino para garantir que foi instalada corretamente.

 ## <br> Arduino
Microcontrolador: ATmega328P

•	Processador central da placa Arduino Uno, responsável por executar o código e controlar os demais componentes.

•	Possui 32KB de memória Flash para armazenar o código, 2KB de SRAM para memória de trabalho e 1KB de EEPROM para armazenamento de dados permanentes.
Tensão de operação: 5V

•	Tensão necessária para alimentar o Arduino Uno.

•	Pode ser fornecida através de uma porta USB ou por uma fonte de alimentação externa.
Tensão de entrada (recomendada): 7-12V

•	Faixa de tensão que pode ser aplicada à entrada do Arduino Uno sem danificá-lo.
Corrente de entrada (DC): 50mA

•	Corrente máxima que o Arduino Uno consome quando alimentado por uma fonte de alimentação externa.
Pinos digitais: 14 (dos quais 6 podem ser usados como PWM)

•	Pinos que podem ser configurados como entrada ou saída digital.

•	Os pinos PWM podem ser usados para gerar sinais analógicos com resolução de 8 bits.
Pinos analógicos: 6

•	Pinos que podem ser configurados para converter sinais analógicos em valores digitais com resolução de 10 bits.
Memória Flash: 32KB

•	Memória utilizada para armazenar o código do programa.
SRAM: 2KB

•	Memória utilizada para armazenar dados temporários.
EEPROM: 1KB

•	Memória utilizada para armazenar dados permanentes.

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/5cc062f2-d6fd-4920-a2c2-14d2bfad81b6)

 ## <br> Jumper Macho-macho
Função: Estabelecer conexões elétricas entre diferentes pontos em uma protoboard.

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/11a90399-855e-4535-a23d-beb59bf07a00)


 ## <br> Protoboard
Tamanho: 400 pontos 
Função: Facilitar a montagem e prototipagem do circuito

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/22a87fb9-032e-432f-a593-0bb0a79cf92d)

 ## <br> Leds Azul
Cor: Azul
•	Emite luz azul com comprimento de onda entre 460 e 480nm.
Comprimento de onda: 460-480nm

•	Comprimento de onda da luz azul emitida pelos LEDs.
Tensão de operação: 3-3.6V

•	Tensão necessária para alimentar os LEDs.
Corrente de operação: 20mA

•	Corrente máxima que cada LED consome.
Ângulo de visão: 120°

•	Ângulo em que a luz azul é emitida pelos LEDs.

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/bfa65f56-aac7-4d77-821d-afcb19c0e0c3)

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/a75b8f6b-f820-49b1-9292-dd4ac458ab06)

## <br> :LDR (Light Dependent Resistor)
 Sensor de luminosidade
 
![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/7caadb95-4b45-4f68-81cb-26d20a373b25)

## <br> LDR (Light Dependent Resistor)

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/3b0644d2-6e22-4c64-a83a-db7559e25e13)

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/61d95582-8dab-42a3-9dbe-d5ed1a9964c8)

## <br> Resistores
Valor: 220 OHMS 
Potência: 1/4W ou 1/2W

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/8ec8ffaa-eada-4abe-8f63-28ed387d61b7)

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/cd6ede84-be62-41ff-95b9-6c76ce2ba6ab)

## <br> Push Button
Botão ligar e desligar

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/e78ab133-0b62-4edf-a2aa-c7564b3056f3)



## <br> Modelo de Montagem 
Montagem:
•	Conecte o sensor de luminosidade ao pino analógico A0 do Arduino.
•	Conecte os LEDs azuis aos pinos digitais 3, 5 e 6 do Arduino, utilizando resistores de 220 ohms em série com cada LED, de acordo com Tutorial de Conexão de LEDs com Arduino: https://roboticsbackend.com/arduino-led-complete-tutorial/
•	Conecte o módulo Wi-Fi ao Arduino de acordo com as instruções do fabricante.
•	Conecte a fonte de alimentação ao Arduino e aos LEDs.
O sensor ECG AD8232 é conectado ao microcontrolador ESP32, que irá processar os dados dos batimentos cardíacos. O ESP32 está ligado a um buzzer, que será utilizado para alertar o usuário em caso de detecção de anomalias cardíacas. Os cabos de alimentação do sensor ECG são conectados às entradas de 3,3V e GND do ESP32, enquanto o sinal de saída do sensor é conectado a um dos pinos analógicos. O buzzer é conectado a um pino digital do ESP32 e a GND. Este sistema é alimentado por uma fonte de 3,7V, adequada para a operação dos componentes eletrônicos envolvidos. Também há a possibilidade de alimentar todo o circuito através de um cabo USB direto de um computador, já que a ESP32 possui entrada para tal.

![image](https://github.com/moniquepavao/luminaria-terapeutica-iot/assets/160164806/4736b3f5-48e7-45a9-851b-0a0ea71e9c22)


## <br> Funcionamento

Funcionamento dos Sensores e Atuadores
Sensor de Luminosidade:
•	Tipo: LDR (Light Dependent Resistor)
•	Função: Medir a intensidade da luz ambiente e adequar a intensidade dos leds azuis.
•	Acionamento: O sensor gera um sinal de tensão variável de acordo com a intensidade da luz. Quanto maior à intensidade da luz, menor a resistência do LDR e maior a tensão gerada.
•	Leitura: O Arduino lê o valor de tensão do sensor e o converte em um valor digital.

 LEDs Azuis:
•	Tipo: LEDs SMD 5050 Azul
•	Função: Emitir luz azul com intensidade ajustável.
•	Acionamento: O Arduino envia sinais PWM (Pulse Width Modulation) para os LEDs, controlando a intensidade da luz emitida.
•	Ajuste da Intensidade: A intensidade da luz emitida pelos LEDs é proporcional ao tempo em que eles estão ligados durante cada ciclo PWM.
•	LEDs azuis: Atuam como os "atores" da luminária, emitindo luz azul na faixa ideal para regular o ritmo circadiano e melhorar o humor. A intensidade dos LEDs é ajustada automaticamente pelo Arduino com base na leitura do sensor de luminosidade.

Módulo Wi-Fi:
•	Tipo: ESP8266
•	Função: Estabelecer conexão à internet e se comunicar com o servidor MQTT.
•	Conexão à Rede: O módulo Wi-Fi se conecta à rede Wi-Fi configurada pelo usuário.
•	Comunicação MQTT: O módulo Wi-Fi utiliza a biblioteca PubSubClient para se conectar ao servidor MQTT e trocar mensagens.

Comunicação com o Broker MQTT
•	Protocolo MQTT: O protocolo MQTT é utilizado para a comunicação entre o protótipo e o servidor MQTT.
•	Tópicos: O protótipo publica e subscreve tópicos específicos no servidor MQTT.
•	Publicação de Dados: O protótipo publica dados sobre o estado da iluminação (ligado/desligado, intensidade da luz) no tópico "luminosidade".
•	Assinatura de Comandos: O protótipo subscreve ao tópico "comandos" e recebe comandos de controle remoto, como acender/apagar as luzes ou ajustar a intensidade.


## <br> Vídeo-demonstração

https://youtu.be/10km3qXzo6A?si=O53vOSiqbL7mzPvt

