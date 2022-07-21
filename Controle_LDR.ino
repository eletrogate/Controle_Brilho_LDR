//nomeia os pinos referentes a cada componente
#define pinLed 6
#define LDR A0 

int valorLDR;  //armazena o valor do sinal analógico enviado pelo LDR
float luminosidade;  //armazena o valor do sinal analógico convertido em PWM 
   
void setup(){  
  Serial.begin(9600);  //inicia de define a velocidade da comunicação serial
  pinMode(LDR, INPUT); //define o pino onde o LDR está conectado como entrada de sinal 
  pinMode(pinLed, OUTPUT); //define o pino onde o led está conectado como saída de sinal 
}  
   
void loop(){  
  valorLDR = analogRead(LDR);  //faz a leitura do LDR e armazena o valor analógico 
  luminosidade = map(valorLDR, 0, 1023, 0, 255); //converte o sinal analógico em PWM
  //exibe os valores lidos no monitor serial
  Serial.print("Valor lido do LDR: ");   
  Serial.println(valorLDR); 
  //exibe os valores convertidos no monitor serial
  Serial.print(" = Luminosidade: ");
  Serial.println(luminosidade);
  analogWrite(pinLed, luminosidade); //liga o led de acordo com o valor do PWM recebido
 }