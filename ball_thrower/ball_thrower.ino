int VOLTAGE_PIN = A0;
int COIL_PIN = 7;
int BALL_LISTENER = 2;
int SECONDS = 1000;

void shoot() {
  digitalWrite(COIL_PIN, LOW);
  delay(1000);
  digitalWrite(COIL_PIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(COIL_PIN, OUTPUT);
  pinMode(BALL_LISTENER, INPUT_PULLUP);
  Serial.println("Cleaning up capacitors");
  shoot();
}

void loop() {
  float voltage = (analogRead(A0) * 220.0 * 1.14) / 1024.0;
  // since using pull_up, 0 means has ball, 1 means no ball
  int ball_in = digitalRead(BALL_LISTENER);
  Serial.print("voltage: ");
  Serial.println(voltage);
  if (voltage > 200 && ball_in == 0) {
    delay(1.5 * SECONDS);
    Serial.println("Shooting!");
    shoot();
  }
}