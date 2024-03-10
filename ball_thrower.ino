int VOLTAGE_PIN = A0;
int COIL_PIN = 2;
int SECONDS = 1000;

void shoot() {
  digitalWrite(COIL_PIN, LOW);
  delay(1000);
  digitalWrite(COIL_PIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(COIL_PIN, OUTPUT);
  Serial.println("Cleaning up capacitors");
  shoot();
}

void loop() {
  float voltage = (analogRead(A0) / 1024.0) * 5.2 * 100;
  Serial.println(voltage);
  if (voltage > 250) {
    Serial.println("Shooting!");
    shoot();
  }
}