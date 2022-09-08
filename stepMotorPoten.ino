#include <Stepper.h>

int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 50,52,51,53);
int stepCount = 0;


void setup() {

}

void loop() {
int sensorReading = analogRead(A0);
int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
if (motorSpeed > 0) {
myStepper.setSpeed(motorSpeed);
myStepper.step(stepsPerRevolution/100);
}
}
