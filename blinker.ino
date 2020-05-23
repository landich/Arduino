void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // Turn ON
  delay(300);             // wait
  digitalWrite(13, LOW);  // Turn OFF
  delay(300);             // wait
}
