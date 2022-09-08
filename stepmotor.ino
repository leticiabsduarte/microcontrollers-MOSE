#include <Stepper.h>

int stepsPerRevolution = 64;
 
Stepper myStepper(stepsPerRevolution, 50,52,51,53);                           // Como o motor exige uma corrente mais alta que a fornecida pelo microcontrolador, faz-se necessário o uso do driver.
                                                                              // Angulo do passo : 5,625 graus => 64 passos/volta (360/64=5,625)
void setup(){
  myStepper.setSpeed(300); 
}
void loop(){     
  for(int i = 0; i < 50; i++){ 
          myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
  }            
  for(int i = 0; i < 50; i++){
          myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
  }
}
