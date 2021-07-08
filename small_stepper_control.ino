#include <Stepper.h>
int secPot = A0;
Stepper oneStepper = Stepper(2048,6,8,7,9);
int full_rot = 2048;
void setup() {
  // put your setup code here, to run once:
  oneStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int secVal = analogRead(secPot);
  int t = full_rot/6;
  oneStepper.step(t);
  Serial.println("moved steps");
  Serial.println(t);
  delay(1000);
  oneStepper.step(-t);
  Serial.println("moved steps");
  Serial.println(t);
  delay(1000);
}
