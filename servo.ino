#include <Servo.h>
#include <LiquidCrystal.h:

LiquidCrystal lcd();
int servoPin = 52;
int potenPin = A0;
int contador = 0;
int leitura;

Servo servo1;

void setup() {
  servo1.attach(servoPin);
  pinMode(potenPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
  lcd.print("Ângulo: ");
}

void loop() {
  leitura = analogRead(potenPin);
  leitura = map(leitura, 0, 1023, 0, 180);
  servo.write(leitura);
  delay(1);

  lcd.setCursor(0,0);
  lcd.print(leitura);
  delay(500);
}
