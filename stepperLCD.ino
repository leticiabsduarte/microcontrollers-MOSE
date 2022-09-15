#include <Stepper.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

int stepsPerRevolution = 64;
int leitura;
 
Stepper myStepper(stepsPerRevolution, 2,4,3,5);                           // Como o motor exige uma corrente mais alta que a fornecida pelo microcontrolador, faz-se necessário o uso do driver.
                                                                              // Angulo do passo : 5,625 graus => 64 passos/volta (360/64=5,625)
void setup(){
  myStepper.setSpeed(300); 
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}
void loop(){     
   for(int i = 0; i < 50; i++){ 
          lcd.setCursor(0,0);
          //lcd.autoscroll();    -> a mensagem não cabe no lcd, mas isso está bugando o lcd. usar delay?
          lcd.print("Sentido Anti-horário"); 
          myStepper.step(stepsPerRevolution);  
          lcd.clear();    
  }                 
  for(int i = 0; i <50; i++){ 
          lcd.setCursor(0,0);       
          lcd.print("Sentido Horario"); 
          myStepper.step(-stepsPerRevolution);     
          lcd.clear();  
  }
}
