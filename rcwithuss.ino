// RC Bluetooth car with HC-SR04 obstacle avoidance
// Ultrasonic: TRIG -> D13, ECHO -> D12
// Your original motor / LED / horn pin definitions preserved

#define in1 3
#define in2 5
#define in3 6
#define in4 11
#define LEDF 9
#define LEDB 8
#define HORN 7
#define LEDP 4

// HC-SR04 pins
const int trigPin = 12;
const int echoPin = 13;
const unsigned int AVOID_DISTANCE_CM = 8; // threshold for avoidance (adjustable)
const unsigned long ECHO_TIMEOUT = 30000UL; // microseconds (~5m), pulseIn timeout

// DBZ
int command; //Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LEDF, OUTPUT); //Set the LED pin.
  pinMode(LEDB, OUTPUT);
  pinMode(HORN, OUTPUT);
  pinMode(LEDP, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600); //Set the baud rate to your Bluetooth module.
}

void loop() {
  // Non-blocking distance check can be used as needed.
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //Initialize with motors stopped.
    switch (command) {
      case 'F':
        if (getDistanceCm() <= AVOID_DISTANCE_CM) {
          avoidObstacle();
        } else {
          forward();
        }
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G': // forward-left
        if (getDistanceCm() <= AVOID_DISTANCE_CM) {
          avoidObstacle();
        } else {
          forwardleft();
        }
        break;
      case 'I': // forward-right
        if (getDistanceCm() <= AVOID_DISTANCE_CM) {
          avoidObstacle();
        } else {
          forwardright();
        }
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case 'W':
        frontledon();
        break;
      case 'w':
        frontledoff();
        break;
      case 'U':
        backledon();
        break;
      case 'u':
        backledoff();
        break;
      case 'V':
        hornon();
        break;
      case 'v':
        hornoff();
        break;
      case 'X':
        parkledon();
        break;
      case 'x':
        parkledoff();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

// ---------- Ultrasonic helper ----------
long getDistanceCm() {
  // Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  unsigned long duration = pulseIn(echoPin, HIGH, ECHO_TIMEOUT); // microseconds
  if (duration == 0) {
    // no echo (timeout) -> treat as far
    return 500;
  }
  long distance = duration / 58; // ~58 us per cm
  return distance;
}

// Simple avoidance maneuver
void avoidObstacle() {
  Stop();
  delay(50);
  // Back up
  back();
  delay(400);
  Stop();
  delay(50);

  // Try turning (choose one direction; here right)
  right();
  delay(400);
  Stop();
  delay(50);

  // After maneuver, re-check distance; if still obstacle, repeat backing up
  long d = getDistanceCm();
  if (d <= AVOID_DISTANCE_CM) {
    // second attempt: back and turn opposite
    back();
    delay(300);
    Stop();
    delay(50);
    left();
    delay(400);
    Stop();
  }

  // After avoidance, remain stopped until next BT command (safer)
}

// ---------- Motor control functions (unchanged) ----------
void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}
void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}
void left() {
  analogWrite(in1, Speed);
  analogWrite(in4, Speed);
}
void right() {
  analogWrite(in2, Speed);
  analogWrite(in3, Speed);
}
void forwardleft() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}
void forwardright() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}
void backright() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}
void backleft() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}
void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}
void frontledon() { digitalWrite(LEDF, HIGH); }
void frontledoff() { digitalWrite(LEDF, LOW); }
void backledon() { digitalWrite(LEDB, HIGH); }
void backledoff() { digitalWrite(LEDB, LOW); }
void hornon() { digitalWrite(HORN, HIGH); }
void hornoff() { digitalWrite(HORN, LOW); }
void parkledon() { digitalWrite(LEDP, HIGH); }
void parkledoff() { digitalWrite(LEDP, LOW); }

void brakeOn() {
  buttonState = command;
  if (buttonState != lastButtonState) {
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    lastButtonState = buttonState;
  }
}
void brakeOff() {
}


