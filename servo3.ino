#include "Servo.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo servoMoto0r;  
  
int const potenciometroPin = A0;  
int const servoMotorPin = 52;  
int PotenVal;            
  
void setup() { 
  Serial.begin(9600);
  lcd.begin (16,2);
  servoMotor.attach(servoMotorPin); 
} 
  
void loop() { 
  lcd.setCursor(0,0);
  lcd.print(" Angulo: ");
  lcd.setCursor(0,1);
  lcd.print (PotenVal);
  lcd.print(" graus ");
  delay(1000);

  Serial.println (PotenVal);
  

  PotenVal = analogRead(potenciometroPin); 
  PotenVal= map(PotenVal, 0, 1023, 0, 180); 

  servoMotor.write(PotenVal); 
  delay(20);   
}
