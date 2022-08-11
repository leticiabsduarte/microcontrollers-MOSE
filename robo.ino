void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);

}

void loop() {
  // Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);

  // Leituras dos sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);

  // Robô anda para FRENTE
  if (direita == false && esquerda == false) {
    analogWrite(MotorA_PWM, veloc3);  // velocidade NORMAL
    analogWrite(MotorB_PWM, veloc3);  // velocidade NORMAL
  }
  // Robô virar para a ESQUERDA
  else if (direita == false && esquerda == true) {
    analogWrite(MotorA_PWM, veloc2);  // motor A NORMAL
    analogWrite(MotorB_PWM, veloc0);  // motor B DEVAGAR
   // delay(400);
  }
  // Robô virar para a DIREITA
  else if (direita == true && esquerda == false) {
    analogWrite(MotorA_PWM, veloc0);  // motor A DEVAGAR
    analogWrite(MotorB_PWM, veloc2);  // motor B NORMAL
   // delay(400);
  }
  // Robô fica PARADO
    else if (direita == true && esquerda == true) {
      analogWrite(MotorA_PWM, veloc0);        // motor A parado
      analogWrite(MotorB_PWM, veloc0);        // motor B parado
    }
  // Imprime no monitor serial
  Serial.print("E: ");
  Serial.print(esquerda);
  Serial.print(" \t - \t D: ");
  Serial.println(direita);

}
