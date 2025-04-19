// Over-Temperature Cutoff Switch
// Version: 0.1

const int tempPin = A0;
const int relayPin = 7;
const float cutoffTempC = 250.0;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Normally open
  Serial.begin(9600);
}

void loop() {
  float temp = readTemperature();
  Serial.println(temp);

  if (temp > cutoffTempC) {
    digitalWrite(relayPin, LOW); // Cut off
  } else {
    digitalWrite(relayPin, HIGH); // Allow gas
  }

  delay(1000);
}

float readTemperature() {
  int analogValue = analogRead(tempPin);
  // Placeholder conversion - replace with sensor-specific formula
  return (analogValue / 1024.0) * 500.0;
}
