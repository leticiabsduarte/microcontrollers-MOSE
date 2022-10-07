#include <LiquidCrystal.h>

#define tempo 800
#define verde 8
#define amarelo 9
#define vermelho 10
#define buzzer 13
#define trigPin 7
#define echoPin 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int trigPin = 7;
int echoPin = 6;

long duracao;
int distancia;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(vermelho, OUTPUT);
pinMode(amarelo, OUTPUT);
pinMode(verde, OUTPUT);
pinMode(buzzer, OUTPUT);  
lcd.begin(16,2);
lcd.setCursor(0,0);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duracao = pulseIn(echoPin, HIGH);

distancia = 200-(duracao/2) / 29,1;
  
Serial.print("Nivel: ");
Serial.print(distancia);
Serial.print("cm");
Serial.println();

lcd.setCursor(0,0);  
lcd.write("Nivel: ");
lcd.print(distancia);
lcd.write(" cm");

  //Se a distância for menor ou igual a 40 cm, o led amarelo acende
if (distancia <= 40){
digitalWrite (amarelo, HIGH);
digitalWrite (vermelho, LOW);
digitalWrite (verde, LOW);
  //Se a distância estiver entre 41 cm e 159, o led verde acende
} else if(distancia <= 159){
digitalWrite (amarelo, LOW);
digitalWrite (vermelho, LOW);
digitalWrite (verde, HIGH);
} 

  //Se a distância for maior ou igual a 160, o led vermelho acende
if (distancia >= 160){
digitalWrite (amarelo, LOW);
digitalWrite (vermelho, HIGH);
digitalWrite (verde, LOW);
}
  //Se a distância for maior ou igual a 180 cm, o led vermelho acende e o alarme toca
if (distancia>=180){
digitalWrite (amarelo, LOW);
digitalWrite (vermelho, HIGH);
digitalWrite (verde, LOW);
  tone(buzzer,440,tempo);
  delay(tempo);
  tone(buzzer,494,tempo);
  delay(tempo);
}
delay(100);
lcd.clear();
}
