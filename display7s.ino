int contador = 0;

void setup()
{
  DDRB = B11111110; // botão
  DDRD = B11111111; // display
}

void loop()
{
  if(digitalRead(8)==0){
    while(digitalRead(8)==0){}
    contador++;
  }
  
  if(digitalRead(9)==1){
    while(digitalRead(9)==1){}
    contador--;
  }
  
  if(contador==0){
  PORTD = B00111111; //0
  }
  
  if(contador==1){
  PORTD = B00000110; //1
  }
  
  if(contador==2){
  PORTD = B01011011; //2
  }
  
  if(contador==3){
  PORTD = B01001111; //3
  }

  if(contador==4){
  PORTD = B01100110; //4
  }
  
  if(contador==5){
  PORTD = B01101101; //5
  }
  
  if(contador==6){
  PORTD = B01111101; //6
  }
  
  if(contador==7){
  PORTD = B00000111; //7
  }

  if(contador==8){
  PORTD = B01111111; //8
  }

  if(contador==9){
  PORTD = B01100111; //9
  }
  
  if(contador>9){
     contador=9;
  }
  
  if(contador<0){
    contador=0;
  }
}
