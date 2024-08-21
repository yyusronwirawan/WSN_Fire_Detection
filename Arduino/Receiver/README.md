Flowchart Alat sensor api receiver

![4](https://user-images.githubusercontent.com/78655390/107149286-607adc80-698a-11eb-99d1-43a6319fbfa3.png)

Alat sensor api receiver ini bisa berdiri sendiri tanpa adanya transmitter. 
Saat alatnya di aktifkan sensor nya langsung bisa bekerja mendeteksi api, jika sensor pada alat ini tidak mendeteksi adanya api maka alatnya akan  mengecek apakah ada kiriman data dari transmitter atau tidak. 
Kalau ada alat inikan mengaktifkan Buzzer dan menggirimkan SMS, kalau tidak ada data yang dikirimkan transmitter, maka alatnya akan loop dari pembacaan sensor api

Pemasangan pin komponen ke arduino

1. nRF24L01 :

                Ground  | GND          VCC  | 3.3V

                CE      | D7           CSN  | D8
                
                SCK     | D13          MOSI | D11
                
                SIMO    | D12
                
2. Buzzer : 
    
                + | D6                - | GND
                
3. Flame Sensor 5 Channel :

                Ground  | GND          VCC  | 5V
                
                A5      | A4
                
                A4      | A3
                
                A3      | A2
                
                A2      | A1
                
                A1      | A0
                
4. GSM 800L :

                Ground  | GND          VCC      | 5V
                SIM_TXD | D9           SIM_RXD  | D10

Untuk lebih visualnya bisa dilihat gambar dibawah

![Screenshot 2021-02-14 224621](https://user-images.githubusercontent.com/78655390/108192239-9cf6c700-7146-11eb-969b-0089c44accad.png)

Fritzing Breadboard View Alat sensor api recever

![Screenshot 2021-02-18 223527](https://user-images.githubusercontent.com/78655390/108380651-a0b74600-7239-11eb-991e-a823a15f5961.png)

Schematic Alat sensor api recever
