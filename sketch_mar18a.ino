// LDR sensor pins
const int ldrNorth = A2;
const int ldrSouth = A4;
const int ldrWest = A5;
const int ldrEast = A7;

void setup() {
    Serial.begin(9600); // Start Serial Monitor
}

void loop() {
    // Read LDR sensor values
    int northValue = analogRead(ldrNorth);
    int southValue = analogRead(ldrSouth);
    int westValue = analogRead(ldrWest);
    int eastValue = analogRead(ldrEast);

    // Print values to Serial Monitor
    Serial.print("North: "); Serial.print(northValue);
    Serial.print(" | South: "); Serial.print(southValue);
    Serial.print(" | West: "); Serial.print(westValue);
    Serial.print(" | East: "); Serial.println(eastValue);

    delay(500); // Wait 500ms before next reading
}
