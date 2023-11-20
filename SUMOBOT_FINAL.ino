#include<AFMotor.h> //Include Adafruit Motor Driver Shield Library
//create motor obejects
AF_DCMotor motor1(1, MOTOR12_1KHZ); //LEFT
AF_DCMotor motor2(2, MOTOR12_1KHZ); //RIGHT

int analogPin=A0;
int analogPin1=A1;

int left=0;
int right=0;

void setup() {
  Serial.begin(9600);
  delay(5000);
   motor1.setSpeed(200); //motor speed is 200-255
  motor2.setSpeed(200);
 

}

void loop() {
  left =analogRead(analogPin);
  right =analogRead(analogPin1);
  Serial.println(left);
  Serial.println(right);
 

  
  if (left>300 && right>300) //no obstructions
  { motor2.run(FORWARD);
  motor1.run(FORWARD);
  

  }
  
  if (left<300 && right<300) //Full Frontal obstruction
 { motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 delay(1000);
 motor1.run(FORWARD);
 motor2.run(RELEASE);
 delay(1000);


 
 }

if (left>300 && right<300) //obstructions at right
 { motor1.run(RELEASE); //turns left
 motor2.run(FORWARD);


 }

 if (left<300 && right>300) //obstructions at left
 { 
 
motor1.run(FORWARD); //turns right
 motor2.run(RELEASE);
 }
 
}
