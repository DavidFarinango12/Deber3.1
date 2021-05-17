////////////////////// ESCLAVO 1 ////////////////

#include <Wire.h>

char dato = ' ';
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;



void setup() {
  Wire.begin(10);
  Serial.begin(9600);
  Wire.onReceive(evento);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}


void loop() {
  
}


void evento(){
  while(Wire.available()){
    dato = Wire.read();
    if(dato){
      digitalWrite(led1,HIGH);
      delay(30000);
      digitalWrite(led2,HIGH);
      delay(30000);
      digitalWrite(led3,HIGH);
      delay(30000);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(30000);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(30000);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW); 
    }
  }
}
