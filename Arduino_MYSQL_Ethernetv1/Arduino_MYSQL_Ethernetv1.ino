#include <SPI.h>
#include <Ethernet.h>//para conectar na intenet
#define portaHTTP 80
byte mac[] = {  
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 }; //endereço mac paraidentificar na rede
  
byte servidor[]={192, 168, 0, 85};//conectar ao servidor local

//char servidor[]="nomedosite.com.br"; conectando ao site web
 
 /*criar um cliente para se conectar*/
 EthernetClient clienteArduino;
 //----------------------------------------------------------
 //AREA PARA DECLARAR SENSORES
 
 
 
 
//----------------------------------------------------------
void setup(){
    Serial.begin(9600);//comunicação comserial
    Ethernet.begin(mac);//comunicando com internet
    
    if(Ethernet.begin(mac)==0){
        Serial.println("Falha ao conectar a rede...");
        Ethernet.begin(mac);
    }
    Serial.print("Conectado a rede com sucesso. IP: ");
    Serial.println(Ethernet.localIP());
}
void loop(){
  
  //----------------------------------------------------------
 //AREA PARA LER SENSORES
 float sensor1=3;
 float sensor2=5;
 float sensor3=7;
//----------------------------------------------------------
    /*  if(clienteArduino.available()){
          char dadosRetornados = clienteArduino.read();
          Serial.print(dadosRetornados);
      }  
      if(!clienteArduino.connected()){
      clienteArduino.stop();
    }
  char comando = Serial.read();
  if(comando =='1'){
    */
    sensor1++;
    sensor2++;
    sensor3++;
   // Serial.println("Conectando ao sevidor...");
   Serial.println("Conectando ao sevidor e enviando os dados: ");
   Serial.print("Sensor 1: ");
   Serial.println(sensor1);
   Serial.print("Sensor 2: ");
   Serial.println(sensor2);
   Serial.print("Sensor 3: ");
   Serial.println(sensor3);
     if(clienteArduino.connect(servidor, portaHTTP)){
       
         //clienteArduino.println("GET /arduino/teste.php HTTP/1.0");
         clienteArduino.print("GET /arduino/salvar.php?");
         clienteArduino.print("sensor1=");
         clienteArduino.print(sensor1);
         clienteArduino.print("&sensor2=");
         clienteArduino.print(sensor2);
         clienteArduino.print("&sensor3=");
         clienteArduino.print(sensor3);
         clienteArduino.println(" HTTP/1.0");
         clienteArduino.println("Host: 192.168.0.85");
         clienteArduino.println("Connection: close");
         clienteArduino.println();
         clienteArduino.stop();
     }else{
     Serial.println( "Falha na conexão com o servidor...");
     clienteArduino.stop();
     }
 // }
     delay(5000);

}
