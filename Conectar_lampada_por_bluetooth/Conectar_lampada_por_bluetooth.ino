/**************************************************************************************
 *                    Conversa Android/Arduino by Sillas Santos                       *
 *                        1-Alterna o estado da lâmpada;                              *
 *                  2-Verifica se a lâmpada está acesa ou apagada;                    *
 *                                                                                    *
 **************************************************************************************/
//Include the SoftwareSerial library
#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bluetooth(1, 0); //TX, RX (Bluetooth)
int readBluetooth; //Variável que irá receber o comando enviado do Android
int lamp_meu_quarto = 13;

void setup() {
 Serial.begin(9600);//Inicia comunicação serial
 pinMode(lamp_meu_quarto,OUTPUT); //Definindo o pino lamp_meu_quarto como saída
}
 
void loop() {
  if(Serial.available()>0){//Verifica se algo chegou via Bluetooth
    readBluetooth=Serial.read();//Grava esse algo lido na variável
    if(readBluetooth == '3'){
      digitalWrite(lamp_meu_quarto,!digitalRead(lamp_meu_quarto));//Alterna estado da lâmpada
    }else{
      if(readBluetooth == '5'){
        delay(250);
        Serial.write(digitalRead(lamp_meu_quarto));//Checa estado da lâmpada
      }
    }
  }
}
