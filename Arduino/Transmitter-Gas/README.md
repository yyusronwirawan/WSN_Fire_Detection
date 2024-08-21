Flowchart  Alat sensor gas transmitter

![3](https://user-images.githubusercontent.com/78655390/107148893-417b4b00-6988-11eb-9a3e-46d92d461275.png)

Sama dengan Flowchart Alat sensor api transmitter, Flowchart  Alat sensor gas MQ-6 transmitter ini juga saat menjalankan alatnya, alatnya akan mencoba mencari koneksi dari Receivernya.
Setelah itu alatnya aktif mendeteksi gas. Jika terdeteksi api Buzzer di dalam alatnya akan menyalah dan akan menggirimkan data ke receiver untuk menggirimkan SMS.

Pemasangan pin komponen ke arduino

1. nRF24L01 :

                Ground  | GND          VCC  | 3.3V

                CE      | D7           CSN  | D8
                
                SCK     | D13          MOSI | D11
                
                SIMO    | D12
                
2. Buzzer : 
    
                + | D6                - | GND
                
3. Sensor Mq :

                Ground  | GND          VCC  | 5V

                
                A0      | A0
                 
Untuk lebih visualnya bisa dilihat gambar dibawah

![Screenshot 2021-02-18 222817](https://user-images.githubusercontent.com/78655390/108379846-e6bfda00-7238-11eb-9ea5-80bdd438fcb7.png)

Fritzing Breadboard View Alat sensor gas transmitter

![Screenshot 2021-02-18 222901](https://user-images.githubusercontent.com/78655390/108380083-1a9aff80-7239-11eb-98ab-046f5103e81b.png)

Schematic Alat sensor gas transmitter
