#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

String countee;
char counter;

void setup() {
  // put your setup code here, to run once:
  SerialPort.begin(115200,SERIAL_8N1,16,17);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  Serial.println("Enter word: ");
  while(Serial.available() == 0){}
    countee = Serial.readString();
    Serial.print("Entered word is: ");
    Serial.println(countee);
    SerialPort.print(countee);

  Serial.println("Enter letter to be counted: ");
  while(Serial.available() == 0){}
    counter = Serial.read();
    Serial.print("Entered letter is: ");
    Serial.println(counter);
    SerialPort.print(counter);  
}