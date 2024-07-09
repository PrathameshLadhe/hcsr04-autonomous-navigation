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
