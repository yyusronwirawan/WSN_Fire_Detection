Flowchart Alat sensor api transmitter 

![2](https://user-images.githubusercontent.com/78655390/107148726-63280280-6987-11eb-8e01-1997c1a7fe5b.png)

Saat menjalankan alatnya, alatnya akan mencoba mencari koneksi dari Receivernya.
Setelah itu mendeteksi api. Jika terdeteksi api Buzzer di dalam alatnya akan menyalah dan akan menggirimkan data ke receiver untuk menggirimkan SMS.

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
                
Untuk lebih visualnya bisa dilihat gambar dibawah

![Screenshot 2021-02-13 233443](https://user-images.githubusercontent.com/78655390/107856590-b56f9480-6e5b-11eb-8365-d3f7a520d4fe.png)

Fritzing Breadboard View Alat sensor api transmitter

![Screenshot 2021-02-13 233733](https://user-images.githubusercontent.com/78655390/107856624-fd8eb700-6e5b-11eb-9ce9-3d54f56cb87b.png)

Schematic Alat sensor api transmitter
