const int soilMoistPin = A5;
const int soilMoistLevelLow = 600;      // your value
const int soilMoistLevelHigh = 250;     // your value
const int relayPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(soilMoistPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int soilMoist = analogRead(soilMoistPin);

  Serial.print("Analog Value: ");
  Serial.print(soilMoist);
  int percentSoilMoist = map(soilMoist, soilMoistLevelLow, soilMoistLevelHigh, 0, 100);

  Serial.print("\t");
  Serial.print(percentSoilMoist);
  Serial.println(" %");

  if(percentSoilMoist < 30) {
    digitalWrite(relayPin, HIGH);
    delay(1*1000); 
    digitalWrite(relayPin, LOW);
  }
  delay(5*1000);
}
