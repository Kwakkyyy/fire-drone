#include <SoftwareSerial.h>
#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;
const int bluetoothTx = 2;                        
const int bluetoothRx = 3;                           
SoftwareSerial bleSerial(bluetoothTx, bluetoothRx);  

void  setup()
{
  Serial.begin(9600);
  bleSerial.begin(9600);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  if (bleSerial.available()) {
    bleSerial.print("Humidity (%): ");
    bleSerial.println((float)DHT11.humidity, 2);

    bleSerial.print("Temperature (C): ");
    bleSerial.println((float)DHT11.temperature, 2);
  }

  delay(1000);
}