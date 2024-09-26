void setup() {
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  delay(10000);

  digitalWrite(6, HIGH);
  digitalWrite(4, LOW);
  delay(3000);

  digitalWrite(2, HIGH);
  digitalWrite(6, LOW);
  delay(10000);
  
  digitalWrite(6, HIGH);
  digitalWrite(2, LOW);
  delay(3000);
}