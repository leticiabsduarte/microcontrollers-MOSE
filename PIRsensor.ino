#define buzzer 2
#define ledverm 7
#define ledamarelo 5; 
#define ledverde 6; 
#define pinopir 3;  

int acionamento;  

void setup()
{
  pinMode(ledverm, OUTPUT); 
  pinMode(ledamarelo, OUTPUT); 
  pinMode(ledverde, OUTPUT); 
  pinMode(pinopir, INPUT);   
  pinMode(buzzer,OUTPUT);
}
void loop()
{
 acionamento = digitalRead(pinopir); 
 if (acionamento == LOW) 
 {
    digitalWrite(ledverm, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(pinoledazul, HIGH);
 }
 else  
 {
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledazul, LOW);

    for(int freq = 200; freq < 2000; freq++) {
      tone(buzzer, freq, 10);
      delay(1);
    }
    for(int freq = 2000; freq > 200; freq--) {
      tone(buzzer, freq, 10);
      delay(1);
    }

    
 }
}
