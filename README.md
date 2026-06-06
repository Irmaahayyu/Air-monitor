# Air Monitoring System with Arduino

## Deskripsi
Sistem monitoring kualitas udara berbasis Arduino Uno menggunakan sensor MQ135 dan DHT11. Sistem mampu memantau suhu, kelembapan, dan kualitas udara secara real-time.

## Fitur
- Monitoring suhu dan kelembapan menggunakan DHT11
- Monitoring kualitas udara menggunakan MQ135
- Tampilan data pada LCD I2C 16x2
- Buzzer aktif saat kualitas udara buruk
- Fan otomatis aktif saat suhu > 35°C
- Monitoring melalui Serial Monitor

## Komponen
- Arduino Uno
- DHT11
- MQ135
- LCD I2C 16x2
- Buzzer
- Relay 1 Channel
- Fan DC 5V
- Breadboard
- Jumper Wire

## Wiring

| Komponen | Pin Arduino |
|-----------|------------|
| DHT11 OUT | D4 |
| MQ135 AO | A0 |
| Buzzer | D8 |
| Relay IN | D7 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Logika Sistem

### Kualitas Udara
| Nilai MQ135 | Status |
|------------|--------|
| < 250 | Baik |
| 250 - 449 | Sedang |
| ≥ 450 | Buruk |

### Fan
| Suhu | Fan |
|-------|------|
| ≤ 35°C | OFF |
| > 35°C | ON |

## Hasil Tampilan LCD

Baris 1:
T:30C H:75%

Baris 2:
Udara:Baik

## Author
Nama: [Nama Kamu]
Universitas Lampung
