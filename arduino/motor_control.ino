//Motor A pins
int in1 = 6;
int in2 = 5;
int ENA = 2;

//Motor B pins
int in3 = 7;
int in4 = 8;
int ENB = 9;

//speed variable
int mySpeed = 0;
char command = 0;

void setup() {
  //serial communication
  Serial.begin(9600);
  Serial.println("Whats next?");
  
  //Motor A pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  //Motor B pins
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void motorDirectionForward() {
  Serial.println("Forward");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(5000);
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
}

void motorDirectionBackward() {
  Serial.println("Backward");
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  delay(5000);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}

void motorLeftTurn() {
  Serial.println("Left Turn");
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  delay(700);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
}

void motorRightTurn() {
  Serial.println("Right Turn");
  digitalWrite(in1, HIGH);
  digitalWrite(in4, HIGH);
  delay(700);
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);
}


void loop() {
  mySpeed = 100;
  analogWrite(ENA, mySpeed);
  analogWrite(ENB, mySpeed);
  
  if (Serial.available() > 0) {
    command = Serial.read();
    
    if (command == 'W' || command == 'w') {
      motorDirectionForward();
    }
    else if (command == 'S' || command == 's') {
      motorDirectionBackward();
    }
    else if (command == 'A' || command == 'a') {
      motorLeftTurn();
    }
    else if (command == 'D' || command == 'd') {
      motorRightTurn();
    }
  }
  
  delay(100);
}
