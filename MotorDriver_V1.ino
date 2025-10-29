// Fade an LED in and out on pin 9
//Motor A pins
int in1 = 6;
int in2 =  5;// LED connected to PWM pin 9
int ENA = 2;
//Motor B pins
int in3 = 7;
int in4 = 8;
int ENB = 9;

//speed varible
int mySpeed = 0;

int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how much to change the brightness each step

void setup() {
  //serial communication
  Serial.begin(9600);
  Serial.println("desired speed");
  //Motor A pins
  pinMode(in1, OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ENA,OUTPUT);
  //Motor B pins
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENB,OUTPUT);
  

}

void loop() {
//check if any value is typed in
if (Serial.available() > 0){
  String inputString = Serial.readStringUntil('\n');
  inputString.trim();

  if (inputString.length() > 0 ){
     mySpeed = inputString.toInt(); // convert to integer
      Serial.print("Variable updated! New value = ");
      Serial.println(mySpeed);
  }
}



  // set the brightness of pin 9:
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ENA, mySpeed);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ENB,mySpeed);
  delay(1000);
 


  // change the brightness for next time
 // brightness = brightness + fadeAmount;

  // reverse the direction of fading at the ends
 // if (brightness <= 0 || brightness >= 100) {
 //   fadeAmount = -fadeAmount;
 // }

  // wait for 30 milliseconds to see the fading effect


}
