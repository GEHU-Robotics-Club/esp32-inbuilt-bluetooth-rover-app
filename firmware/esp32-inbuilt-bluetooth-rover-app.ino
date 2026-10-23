#include "BluetoothSerial.h" 
 
BluetoothSerial SerialBT; 
 
// Motor pins (same as before) 
const int IN1 = 26;  // Left forward 
const int IN2 = 27;  // Left backward 
const int IN3 = 13;  // Right forward 
const int IN4 = 12;  // Right backward 
const int ENA = 32;  // Left PWM speed 
const int ENB = 33;  // Right PWM speed 
 
int speed = 200;     // Default speed (0-255) 
 
void setup() { 
  Serial.begin(115200); 
  SerialBT.begin("RobotCar");  // Bluetooth name – phone se connect karna 
 
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT); 
 
  stopCar();  // Shuru mein rukna chahiye 
  Serial.println("Bluetooth Robot Car Ready! 'F' = aage, 'B' = peeche"); 
} 
 
void loop() { 
  if (SerialBT.available()) { 
    char cmd = SerialBT.read(); 
 
    // Speed set karne wale commands 
    if (cmd == '0') speed = 0; 
    else if (cmd == '1') speed = 25; 
    else if (cmd == '2') speed = 51; 
    else if (cmd == '3') speed = 77; 
    else if (cmd == '4') speed = 102; 
    else if (cmd == '5') speed = 128; 
    else if (cmd == '6') speed = 153; 
    else if (cmd == '7') speed = 179; 

    else if (cmd == '8') speed = 204; 
    else if (cmd == '9') speed = 230; 
    else if (cmd == 'q') speed = 255; 
    else if (cmd == 'D') stopCar();  // Sab stop 
 
    // Direction commands 
    else if (cmd == 'F') moveForward(); 
    else if (cmd == 'B') moveBackward(); 
    else if (cmd == 'L') turnLeft(); 
    else if (cmd == 'R') turnRight(); 
    else if (cmd == 'G') forwardLeft(); 
    else if (cmd == 'I') forwardRight(); 
    else if (cmd == 'H') backLeft(); 
    else if (cmd == 'J') backRight(); 
    else if (cmd == 'S') stopCar(); 
 
    // Debugging ke liye (optional) 
    Serial.print("Command mila: "); 
    Serial.println(cmd); 
  } 
} 
 
// ────────────────────────────────────────────── 
// Ab forward aur backward reverse kar diye hain 
// ────────────────────────────────────────────── 
 
void moveForward() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH); 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed); 
} 
 
void moveBackward() { 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed); 
} 
 
void turnLeft() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);   // Left peeche 
  digitalWrite(IN3, HIGH); 

  digitalWrite(IN4, LOW);    // Right aage 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed); 
} 
 
void turnRight() { 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);    // Left aage 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);   // Right peeche 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed); 
} 
 
void forwardLeft() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH); 
  analogWrite(ENA, speed / 2);   // Left thoda slow 
  analogWrite(ENB, speed); 
} 
 
void forwardRight() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH); 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed / 2);   // Right thoda slow 
} 
 
void backLeft() { 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, speed / 2); 
  analogWrite(ENB, speed); 
} 
 
void backRight() { 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, speed); 
  analogWrite(ENB, speed / 2); 

} 
 
void stopCar() { 
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0); 
}