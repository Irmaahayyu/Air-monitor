#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define MQ135 A0
#define BUZZER 8
#define FAN 7

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  dht.begin();
  delay(3000);

  pinMode(BUZZER, OUTPUT);
  pinMode(FAN, OUTPUT);

  digitalWrite(BUZZER, LOW);

  // Relay biasanya active LOW
  digitalWrite(FAN, HIGH);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Air Monitor");
  delay(2000);
  lcd.clear();

  Serial.println("=== Sistem Monitoring Kualitas Udara ===");
}

void loop() {

  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  int kualitasUdara = analogRead(MQ135);

  String statusUdara;

  // MQ135 + Buzzer
  if (kualitasUdara < 250) {
    statusUdara = "Baik";
    digitalWrite(BUZZER, LOW);
  }
  else if (kualitasUdara < 450) {
    statusUdara = "Sedang";
    digitalWrite(BUZZER, LOW);
  }
  else {
    statusUdara = "Buruk";
    digitalWrite(BUZZER, HIGH);
  }

  // Fan ON jika suhu > 30°C
  if (!isnan(suhu) && suhu > 35) {
    digitalWrite(FAN, LOW);   // ON (relay active LOW)
  } else {
    digitalWrite(FAN, HIGH);  // OFF
  }

  // Serial Monitor
  Serial.print("Suhu: ");
  if (isnan(suhu)) {
    Serial.print("Gagal");
  } else {
    Serial.print(suhu);
    Serial.print(" C");
  }

  Serial.print(" | Kelembapan: ");
  if (isnan(kelembapan)) {
    Serial.print("Gagal");
  } else {
    Serial.print(kelembapan);
    Serial.print("%");
  }

  Serial.print(" | MQ135: ");
  Serial.print(kualitasUdara);

  Serial.print(" | Status: ");
  Serial.println(statusUdara);

  // LCD Baris 1
  lcd.setCursor(0, 0);

  if (!isnan(suhu)) {
    lcd.print("T:");
    lcd.print(suhu, 1);
    lcd.print("C ");
  } else {
    lcd.print("T:Gagal ");
  }

  lcd.print("H:");

  if (!isnan(kelembapan)) {
    lcd.print((int)kelembapan);
    lcd.print("% ");
  }

  lcd.print("   ");

  // LCD Baris 2
  lcd.setCursor(0, 1);
  lcd.print("Udara:");
  lcd.print(statusUdara);
  lcd.print("     ");

  delay(2000);
}
