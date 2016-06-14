/*Sensor de Temperatura y Humedad DHT11<br>Instrucciones:
Recuerda descargar la libreria DHT para poder utilizar este sensor
Conectaremos el Sensor DHT11 a 5v y el pin de señal a la entrada digital 8
*/
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {  
  int h = dht.readHumidity();// Lee la humedad
  int t= dht.readTemperature();//Lee la temperatura

  Serial.print("Humedad Relativa: ");                 
  Serial.print(h);//Escribe la humedad
  Serial.println(" %");                     
  delay (2500);

  Serial.print("Temperatura: ");                  
  Serial.print(t);//Escribe la temperatura
  Serial.println(" Cº");                   
  delay (2500);
  Serial.println ();
}
