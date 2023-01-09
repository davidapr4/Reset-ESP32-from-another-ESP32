// Sending/Receiving example
#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial Receiver(2); // Define a Serial port instance called 'Receiver' using serial port 2

#define Receiver_Txd_pin 27
#define Receiver_Rxd_pin 14

long myInterval = 5000;
long myTime;
bool alive;

void setup() {
  //Serial.begin(Baud Rate, Data Protocol, Txd pin, Rxd pin);
  Serial.begin(9600);                                                   // Define and start serial monitor
  Receiver.begin(9600, SERIAL_8N1, Receiver_Txd_pin, Receiver_Rxd_pin); // Define and start Receiver serial port
  pinMode(2,OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {   
  while (Receiver.available()) {                         // Wait for the Receiver to get the characters
    char x = Receiver.read();
    Serial.print("data esp2 : ");                     
    Serial.println(x);                     
    alive = true;                           
  }

  if(millis() >= myTime + myInterval){
    myTime = millis();
    Serial.println(alive);
    if(alive==true){
      alive = false;
    }

    else{
      digitalWrite(2,LOW);
      delay(1000);
      digitalWrite(2,HIGH);
    }
    
    
  }
  
}