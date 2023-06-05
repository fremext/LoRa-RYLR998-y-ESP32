String lora_band = "915000000"; //Banda de frecuencia (Hz) dependera el País/Región donde se encuentre 
String lora_networkid = "18";   //Identificación de la red Lora
String lora_address = "2";      //Dirección del módulo Lora

int led = 22; //Led conectado al pin D22 del esp32

String textoEntrada; //Almacena los datos recibidos del emisor 

 ()
{

  pinMode(led,OUTPUT); //Modo de salida el pin D22 del led
  Serial2.begin(115200,SERIAL_8N1, 16,17); //puerto serie2 (pin 16RXD,17TXD UART del esp32) 
  Serial.begin(115200); //Velocidad 115200
   
  
  delay(1500);
  Serial2.println("AT+BAND=" + lora_band); ////Configuracion del modulo/Puerto serie (UART 2)
  delay(500);
  Serial2.println("AT+NETWORKID=" + lora_networkid);
  delay(500);
  Serial2.println("AT+ADDRESS=" + lora_address);
  delay(1000);
  
}

void loop(){ 
  if(Serial2.available()) {  //Monetizaremos Puerto serie UART 2 
    
    textoEntrada = Serial2.readString(); //Almacena los datos recibidos del emisor 
    Serial.println(textoEntrada);  //Muestra por consola datos recibidos del emisor 
  
    if(textoEntrada.indexOf("ON") > 0) { //Busca la palabra "ON"
      digitalWrite(led, !digitalRead(led)); //Si encuentra la palabra "ON" led encendido
    }                                       //Si no encuentra la palabra "ON" led apagado

    
  }
}


