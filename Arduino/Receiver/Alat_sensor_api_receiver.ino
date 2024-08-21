#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>
#define STM800_TX_PIN 2
#define STM800_RX_PIN 3

SoftwareSerial serialSIM800(STM800_TX_PIN, STM800_RX_PIN);

int sensorValue; 
int outputPin = 6;

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(7, 8); // CE, CSN

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
int averagenilai0;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  pinMode(outputPin, OUTPUT);
  while(!Serial);
  serialSIM800.begin(9600);
}

void loop() {
  SensorApi();
  if (radio.available()) {
        radio.read(&sensorValue, sizeof(sensorValue));
        Serial.println(sensorValue);
        if (sensorValue >= 512) {
            digitalWrite(outputPin, HIGH);
            Serial.println("Tidak Terdeteksi Api / Gas");
            serialSIM800.write("AT+CMGF=1\r\n");
            delay(1000);
            serialSIM800.write("AT+CMGS=\"08xxxxxxx\"\r\n"); //nomor Hp yang dihubungi
            delay(1000);
            serialSIM800.write("Terdeteksi Api / Gas Di Alamat Banaran, Sendangadi, Kec. Mlati, Kabupaten Sleman, Daerah Istimewa Yogyakarta 55285 https://maps.app.goo.gl/Pu9iarQyLN5iEAiRA");
            delay(1000);
            serialSIM800.write((char)26);
            delay(10000);
            Serial.println("SMS Terkirim");
        } else {
            digitalWrite(outputPin, LOW);
            Serial.println("Tidak Terdeteksi Api / Gas");
        }
  }else {
        Serial.println("Data was not found"); 
  }
}

void SensorApi(){
  nilaisensor0 = analogRead(sensor0);
  nilaisensor1 = analogRead(sensor1);
  nilaisensor2 = analogRead(sensor2);
  nilaisensor3 = analogRead(sensor3);
  nilaisensor4 = analogRead(sensor4);
  averagenilai0 = (nilaisensor0 + nilaisensor1 + nilaisensor2 +nilaisensor3 + nilaisensor3)/4;

  if(averagenilai0  >= 512){
      digitalWrite(outputPin, HIGH);
      Serial.println(averagenilai0); 
      serialSIM800.write("AT+CMGF=1\r\n");
      delay(1000);
      serialSIM800.write("AT+CMGS=\"082210410052\"\r\n");
      delay(1000);
      serialSIM800.write("Terdeteksi Api / Gas Di Alamat Banaran, Sendangadi, Kec. Mlati, Kabupaten Sleman, Daerah Istimewa Yogyakarta 55285 https://maps.app.goo.gl/Pu9iarQyLN5iEAiRA");
      delay(1000);
      serialSIM800.write((char)26);
      delay(10000);
      Serial.println("SMS Terkirim");
  }else{
    digitalWrite(outputPin, LOW);
  }
}
