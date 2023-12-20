#include <AFMotor.h>

// Initial motors pin which are connected to the motor driver sheild
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char data; // Declare data outside the if block

void setup() {
  Serial.println("Waiting for Bluetooth connection...");
  Serial.begin(9600);  // Set the baud rate to your Bluetooth module.
  Stop();  // Initialize with motors stopped.
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print("Received: ");
    Serial.println(data);
    Stop(); // Initialize with motors stopped

    // Change pin mode only if the new command is different from the previous.
    switch (data) {
      case 'F':
        Serial.println("Moving Forward");
        forward();
        break;
      case 'B':
        Serial.println("Moving Backward");
        back();
        break;
      case 'L':
        Serial.println("Turning Left");
        left();
        break;
      case 'R':
        Serial.println("Turning Right");
        right();
        break;
    }
  }
}

void forward() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD); // Rotate the motor clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(FORWARD); // Rotate the motor clockwise
  motor3.setSpeed(255);// Define maximum velocity
  motor3.run(FORWARD); // Rotate the motor clockwise
  motor4.setSpeed(255);// Define maximum velocity
  motor4.run(FORWARD); // Rotate the motor clockwise
}

void back() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(BACKWARD); // Rotate the motor anti-clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(BACKWARD); // Rotate the motor anti-clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(BACKWARD); // Rotate the motor anti-clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(BACKWARD); // Rotate the motor anti-clockwise
}

void left() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(BACKWARD); // Rotate the motor anti-clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(BACKWARD); // Rotate the motor anti-clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(FORWARD);  // Rotate the motor clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(FORWARD);  // Rotate the motor clockwise
}

void right() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD); // Rotate the motor clockwise
  motor2.setSpeed(255); // Define maximum velocity
  motor2.run(FORWARD); // Rotate the motor clockwise
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(BACKWARD); // Rotate the motor anti-clockwise
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(BACKWARD); // Rotate the motor anti-clockwise
}

void Stop() {
  motor1.setSpeed(0); // Define minimum velocity
  motor1.run(RELEASE); // Stop the motor when releasing the button
  motor2.setSpeed(0); // Define minimum velocity
  motor2.run(RELEASE); // Stop the motor when releasing the button
  motor3.setSpeed(0); // Define minimum velocity
  motor3.run(RELEASE); // Stop the motor when releasing the button
  motor4.setSpeed(0); // Define minimum velocity
  motor4.run(RELEASE); // Stop the motor when releasing the button
}
