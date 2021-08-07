const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;
const int POT = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (POT, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int spd_val = analogRead(POT);
  spd_val = map (spd_val, 0,1023,0,255);
  Serial.println(spd_val);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, spd_val);
  delay(15);
}
