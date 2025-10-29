
//Motor A pins
int in1 = 6;
int in2 =  5;
int ENA = 2;
//Motor B pins
int in3 = 7;
int in4 = 8;
int ENB = 9;

//speed varible
int mySpeed = 0;
int direction = 0;

int brightness = 0;  
int fadeAmount = 5; 

void setup() {
  //serial communication
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Serial.println("Whats next?");
  
  //Motor A pins
  pinMode(in1, OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ENA,OUTPUT);
  //Motor B pins
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENB,OUTPUT);
  
}

void motorDirectionForward() {
  Serial.println("Foward");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);

  delay(500);
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  direction = 0;
}
void motorDirectionBackward() {
  Serial.println("Backward");
  digitalWrite(in2, HIGH);
  digitalWrite(in4,HIGH);
  delay(500);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  direction = 0;
}
void leftTurn() {
  Serial.println("Turning Left");
  digitalWrite(in2, HIGH);
  digitalWrite(in3,HIGH);
 
  
  delay(500);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  direction = 0;
}

void rightTurn() {
  Serial.println("Turning Right");
  digitalWrite(in2, LOW);
  digitalWrite(in4,HIGH);
  delay(500);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  direction = 0;
}



void loop() {

  mySpeed = 250;
  digitalWrite(ENA, mySpeed);
  digitalWrite(ENB, mySpeed);
  if (Serial.available() > 1) {
    direction = Serial.parseInt();   // update global variable
    Serial.print("Variable updated! New value = ");
    Serial.println(direction);
  }
  
    Serial.println(direction);

  
   if (direction == 2) {
    motorDirectionForward();   // call the function
  }
  if (direction == 1){
    motorDirectionBackward();
  }
  
if (direction == 3){
    leftTurn();
  }
delay(1000);
}
