#include <SoftwareSerial.h>
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
  if (bleSerial.available()) {
    Serial.write(bleSerial.read());
  }
  if (Serial.available()) {
    bleSerial.write(Serial.read());
  }
}
