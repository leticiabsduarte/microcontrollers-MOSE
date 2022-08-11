#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>
  
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
Servo myservo;
int potpin = 0;
int val;                    

void setup(){
  myservo.attach(3);
  lcd.begin(16, 2);
}
  void loop(){
  val = analogRead(potpin);             
  val = map(val, 0, 1023, 0, 180);     
  myservo.write(val);                  
  delay(15);  
  lcd.clear();
   lcd.print("ANG SERVO");
  lcd.setCursor(0, 1);  
  lcd.print(val);                       
}
