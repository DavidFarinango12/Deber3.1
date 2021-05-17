/*
 *CAPITULO III: COMUNICACION I2C
 *DEBER 3: COMUNICACION ENTRE 1 ARDUINO MAESTRO Y 3 ESCLAVOS
 *OBJETIVO: Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales, 
 *          los cuales deberán encenderse de forma síncrona   y ordenada. Los leds del primer esclavo deberán entran en funcionamiento cuando 
 *          se ingrese 'Cualquier caracter', luego cuando se ingrese otro 'Cualquier caracter 2' entrará en     funcionamiento el esclavo 2, 
 *          y después cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3.
 *NOMBRE: RAFAEL FARINANGO
 */

/////////////////////////////////////////MASTER/////////////////////////////////

#include <Wire.h>

char dato;
int vector[]={10,11,12};
int cont = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}


void loop() {
  if(Serial.available()){
    dato = Serial.read();
    cont++;
    Serial.println(dato);
    
    Wire.beginTransmission(vector[cont-1]);
    Wire.write(dato);
    Wire.endTransmission();

    if(cont == 3){
      cont = 0;
    }

//    Wire.beginTransmission(11);
//    Wire.write(dato);
//    Wire.endTransmission();
//
//    Wire.beginTransmission(12);
//    Wire.write(dato);
//    Wire.endTransmission();  
    
  }

}
