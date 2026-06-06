# Air Quality Monitoring System

## Deskripsi
Sistem monitoring kualitas udara berbasis Arduino menggunakan sensor MQ135 dan DHT11. Data suhu, kelembapan, dan kualitas udara ditampilkan pada LCD I2C serta Serial Monitor.

## Komponen
- Arduino Uno
- MQ135
- DHT11
- LCD I2C 16x2
- Buzzer
- Breadboard
- Kabel jumper

## Pin yang Digunakan

| Komponen | Pin |
|-----------|-----|
| DHT11 | D2 |
| MQ135 | A0 |
| Buzzer | D8 |
| LCD I2C SDA | A4 |
| LCD I2C SCL | A5 |

## Cara Kerja
1. DHT11 membaca suhu dan kelembapan.
2. MQ135 membaca kualitas udara.
3. Data ditampilkan pada LCD dan Serial Monitor.
4. Jika kualitas udara buruk, buzzer akan menyala.

## Hasil
Contoh output Serial Monitor:

```text
Suhu: 29.0 C | Kelembapan: 75% | MQ135: 520 | Kualitas udara: Buruk
````
