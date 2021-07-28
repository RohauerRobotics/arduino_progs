const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;
const int POT = A0;
const int LIMIT_1 = 5;
const int LIMIT_2 = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (POT, INPUT);
  pinMode(LIMIT_1, INPUT_PULLUP);
  pinMode(LIMIT_2, INPUT_PULLUP);
  Serial.begin(9600);
}
int dir_up(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2, LOW);
 }

int dir_down(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  }

void loop() {
  int dir_up = false;
  // put your main code here, to run repeatedly:
  int top_stop = digitalRead(LIMIT_1);
  int bot_stop = digitalRead(LIMIT_2);
  int speed_val = map(analogRead(POT),0,1023,0,255);
  // Serial.println(speed_val);
  if (dir_up == false){
    dir_down;
    if (bot_stop == HIGH){
      dir_up = true;
      Serial.println("Bottom Reached");
      }
    else{
      analogWrite(ENA, speed_val);
      } 
  }
  else {
    dir_up;
    if (top_stop == HIGH){
      dir_up = false;
      Serial.println("Top Reached");
      }
    else {
      analogWrite(ENA, speed_val);
      }
    } 
  delay(15);
}
