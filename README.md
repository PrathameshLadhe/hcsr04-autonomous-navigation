# 🚗 Arduino Obstacle Detection and Steering Control

This project utilizes an Arduino, an HC-SR04 ultrasonic sensor, and a motor to create a vehicle capable of detecting obstacles and steering to avoid them.

## 📦 Components

- Arduino Uno (or compatible board)
- HC-SR04 Ultrasonic Sensor
- Motor (for steering)
- Motor Driver (if required)
- Jumper Wires
- Breadboard (optional)

## 🔧 Wiring

### HC-SR04 Ultrasonic Sensor:
- VCC to 5V
- GND to GND
- TRIG to pin 9
- ECHO to pin 10

### Motor for Steering:
- Control signal to pin 3 (PWM pin)
- Connect the motor to a motor driver if necessary, depending on your motor specifications.

## 📝 Code

Upload the following code to your Arduino:

```cpp
// Define pins for HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Define pin for motor
const int motorPin = 3;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Control motor based on distance
  if (distance < 20) {
    // If obstacle is detected within 20 cm, steer the vehicle
    analogWrite(motorPin, 255);  // Full speed to steer
  } else {
    // No obstacle, go straight
    analogWrite(motorPin, 0);  // Stop steering
  }
  
  // Delay before next measurement
  delay(100);
}
