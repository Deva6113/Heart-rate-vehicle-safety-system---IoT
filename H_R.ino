 

const int heartRateSensorPin = A0;
const int minHeartRate = 60;
const int maxHeartRate = 130;
const int relayPin = 12;
const int ledPin = 10;

void setup() {
  pinMode(heartRateSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);  
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int heartRateSensorValue = analogRead(heartRateSensorPin);
  int heartRate = map(heartRateSensorValue, 0, 1023, 0, 200); // Map the sensor value to 0-200 range
  heartRate = constrain(heartRate, 0, 200); // Limit the heart rate to 0-200
  Serial.println(heartRate);
  if (heartRate < minHeartRate || heartRate > maxHeartRate) {
    digitalWrite(relayPin, LOW);
     digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
     digitalWrite(ledPin, HIGH);
  }

  delay(500);
}


