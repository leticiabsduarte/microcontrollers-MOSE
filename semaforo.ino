void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop() {
pinMode(7,HIGH);
delay(3000);
pinMode(7,LOW);

pinMode(6,HIGH);
delay(3000);
pinMode(6,LOW);

pinMode(5,HIGH);
delay(3000);
pinMode(5,LOW);

}
