// Sending/Receiving example
#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial Sender(1);   // Define a Serial port instance called 'Sender' using serial port 1

#define Sender_Txd_pin 13
#define Sender_Rxd_pin 12

bool alive = true;

long myTime;
long myTime2;
long interval_T1 = 1000; // blink every 1 second
long interval_T2 = 10000;
long interval_T3 = 60000;

void setup() {
  //Serial.begin(Baud Rate, Data Protocol, Txd pin, Rxd pin);
  Serial.begin(9600);                                             // Define and start serial monitor
  Sender.begin(9600, SERIAL_8N1, Sender_Txd_pin, Sender_Rxd_pin); // Define and start Sender serial port
  // pinMode(2,OUTPUT);
  // digitalWrite(2, HIGH);
  // delay(1000);
  // digitalWrite(2, LOW);
  // delay(1000);
}

void loop() {

  if (millis() >= myTime + interval_T1) {
    myTime = millis();
    Serial.println("abc");
    Sender.println(alive);
  }

  if (millis() >= myTime2 + interval_T2) {
    myTime2 = millis();
    while (true){
      Serial.println("test");
      delay(1000);
    }
  }

  // if (millis() >= myTime + interval_T3) {
  //   myTime = millis();
  //   Serial.print("data 1 menit : " + alive);
  //   if (alive==false){
  //     digitalWrite(2, LOW);
  //     ESP.restart();
  //   }
  // }

  
}