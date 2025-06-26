#include <Stepper.h>

const int stepsPerRevolution = 200;

// Initialize stepper motors
Stepper motorAzimuth(stepsPerRevolution, 10, 12, 11, 13);
Stepper motorTilt1(stepsPerRevolution, 2, 4, 3, 5);
Stepper motorTilt2(stepsPerRevolution, 6, 8, 7, 9);

// LDR sensor pins
const int ldrTopLeft = A4;
const int ldrTopRight = A2;
const int ldrBottomLeft = A3;
const int ldrBottomRight = A1;

// Movement limits
int azimuthPosition = 0;
int tiltPosition = 90;
int azimuthLimit = 180;  // Use -180 to 180 for full rotation
int tiltLimitHigh = 170; // Prevent over-tilting
int tiltLimitLow = 10;

// Sensitivity settings
const int threshold = 10;  // More sensitivity for small adjustments
const int stepSize = stepsPerRevolution / 200;
const int delayTime = 5;

void setup() {
    motorAzimuth.setSpeed(100);  
    motorTilt1.setSpeed(100);
    motorTilt2.setSpeed(100);
    Serial.begin(9600);
}

void loop() {
    // Read raw LDR sensor values (0 to 1023)
    int topLeft = analogRead(ldrTopLeft);
    int topRight = analogRead(ldrTopRight);
    int bottomLeft = analogRead(ldrBottomLeft);
    int bottomRight = analogRead(ldrBottomRight);

    // Map values to 0-100 scale
    int topLeftValue = map(topLeft, 0, 1000, 0, 100);
    int topRightValue = map(topRight, 0, 500, 0, 100);
    int bottomLeftValue = map(bottomLeft, 0, 940, 0, 100);
    int bottomRightValue = map(bottomRight, 0, 1010, 0, 100);

    // Debugging outputs
    Serial.print("Top Left:"); Serial.print(topLeftValue);
    Serial.print(" Bottom Left:"); Serial.print(bottomLeftValue);
    Serial.print(" Top Right:"); Serial.print(topRightValue);
    Serial.print(" Bottom Right:"); Serial.println(bottomRightValue);

    // Calculate differences using **mapped values** now
    int verticalDifference = (topLeftValue + topRightValue) - (bottomLeftValue + bottomRightValue);
    int horizontalDifference = topLeftValue - topRightValue;

    // **Fix: Ensure azimuth moves the shorter distance**
    if (abs(horizontalDifference) > threshold) {
        if (horizontalDifference > 0) {  
            // Move west
            azimuthPosition -= stepSize;
            motorAzimuth.step(-stepSize);
            Serial.println("Moving left");
        } else {  
            // Move east
            azimuthPosition += stepSize;
            motorAzimuth.step(stepSize);
            Serial.println("Moving right");
        }

        // **Keep azimuth within -180 to 180**
        if (azimuthPosition > 180) azimuthPosition -= 360;
        if (azimuthPosition < -180) azimuthPosition += 360;
    } else {
        Serial.println("Azimuth stable");
    }

    // **Fix: Use mapped values for tilt movement**
    if (abs(verticalDifference) > threshold) {
        if (verticalDifference > 0) {  
            // Move north (tilt up)
            if (tiltPosition - stepSize >= tiltLimitLow) {
                tiltPosition -= stepSize;
                motorTilt1.step(stepSize);
                motorTilt2.step(-stepSize); 
                Serial.println("Tilting up");
            }
        } else {  
            // Move south (tilt down)
            if (tiltPosition + stepSize <= tiltLimitHigh) {
                tiltPosition += stepSize;
                motorTilt1.step(-stepSize);
                motorTilt2.step(stepSize); 
                Serial.println("Tilting down");
            }
        }
    } else {
        Serial.println("Tilt stable");
    }

    delay(delayTime);
}