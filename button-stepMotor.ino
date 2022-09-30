#include <Stepper.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(52,53,50,51,48,49);

int stepsPerRevolution = 64;
int leitura;
int i = 0;

Stepper myStepper(stepsPerRevolution, 22,26,24,28);                           // Como o motor exige uma corrente mais alta que a fornecida pelo microcontrolador, faz-se necessário o uso do driver.
                                                                              // Angulo do passo : 5,625 graus => 64 passos/volta (360/64=5,625)
void setup(){
  myStepper.setSpeed(300); 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}
void loop(){  
   if (digitalRead(2) == LOW){
          i++;
          myStepper.step(stepsPerRevolution);
          lcd.setCursor(0,0); 
          lcd.print("Angulo");  
          lcd.setCursor(0,1);   
          lcd.print(i*5.625);  
  } 
    if (digitalRead(3) == LOW){              
      i++;
      myStepper.step (-stepsPerRevolution);
      lcd.setCursor(0,0);  
      lcd.print("angulo"); 
      lcd.setCursor(0,1); 
      lcd.print(-i*5.625);   
  }
}
