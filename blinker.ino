void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn ON
  delay(300);                      // wait
  digitalWrite(LED_BUILTIN, LOW);  // Turn OFF
  delay(300);                      // wait
}
