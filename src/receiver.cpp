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
  while(SerialPort.available() == 0){}
    countee = SerialPort.readString();
    Serial.print("Received word is: ");
    Serial.println(countee);

  while(SerialPort.available()==0){}
    counter = SerialPort.read();
    Serial.print("Received letter is: ");
    Serial.println(counter);

    Serial.println("Inputs are: ");
    Serial.print("Word: ");
    Serial.println(countee);
    Serial.print("Letter: ");
    Serial.println(counter);
  
    int counteelength = countee.length() + 1;
    char counteechar[counteelength];
    countee.toCharArray(counteechar, counteelength);

    int x = 0;
    for (int i = 0; i<counteelength; i++){
        if (counteechar[i] == counter){
            x++;
        }
    }
    Serial.print("Number of ");
    Serial.print(counter);
    Serial.print("'s is: ");
    Serial.println(x);
}