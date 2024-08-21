#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define MQ2pin (0)

int sensorValue; 
int outputPin = 6;

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(7, 8); // CE, CSN

void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setDataRate(RF24_250KBPS);
  pinMode(outputPin,OUTPUT);
}

int i=0;

void loop(){
  sensorValue = analogRead(MQ2pin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  if(sensorValue > 400){
    Serial.print(" | Smoke detected!");
    digitalWrite(outputPin, HIGH);
    sensorValue = analogRead(sensorValue);
    radio.write(&sensorValue, sizeof(sensorValue));
    i=1;   
  }else{
    digitalWrite(outputPin, LOW);
    if(i==1){
    sensorValue = analogRead(sensorValue);
    radio.write(&sensorValue, sizeof(sensorValue));
    i=0;
    }
  }
  Serial.println("");
}
