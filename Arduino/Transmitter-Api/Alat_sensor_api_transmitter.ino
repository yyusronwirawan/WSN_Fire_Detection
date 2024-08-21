#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int sensor0 = A0;
int sensor1 = A1; 
int sensor2 = A2; 
int sensor3 = A3;
int sensor4 = A4;

int nilaisensor0;
int nilaisensor1;
int nilaisensor2;
int nilaisensor3;
int nilaisensor4;
int sensorValue;

int outputPin = 10;

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(7, 8); // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setDataRate(RF24_250KBPS);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
}

int i=0;

void loop() {
  nilaisensor0 = analogRead(sensor0);
  nilaisensor1 = analogRead(sensor1);
  nilaisensor2 = analogRead(sensor2);
  nilaisensor3 = analogRead(sensor3);
  nilaisensor4 = analogRead(sensor4);
  sensorValue = (nilaisensor0 + nilaisensor1 + nilaisensor2 +nilaisensor3 + nilaisensor3)/4;
  
  if(sensorValue  >= 512){
      digitalWrite(outputPin, HIGH);
      sensorValue = analogRead(sensorValue);
      radio.write(&sensorValue, sizeof(sensorValue));
      Serial.println(sensorValue); 
      i=1;   
  }else{
    digitalWrite(outputPin, LOW);
   if(i=1){
    sensorValue = analogRead(sensorValue);
    radio.write(&sensorValue, sizeof(sensorValue));
    i=0;
   }
  } 
}
