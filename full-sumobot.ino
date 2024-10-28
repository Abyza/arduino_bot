#include <AFMotor.h>
AF_DCMotor motorR(1);
AF_DCMotor motorL(2);

int ultraT = 9;
int ultraE = 10;
long duration;
int distance;

#define irR A2
#define irL A3


void setup() {
  // put your setup code here, to run once:
  motorR.setSpeed(225);
  motorL.setSpeed(225);

  pinMode(ultraT, OUTPUT);
  pinMode(ultraE, INPUT);

  Serial.begin(9600);

  pinMode(irL,INPUT);
  pinMode(irR,INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  //motorL.run(FORWARD);
  //motorR.run(BACKWARD);
  // 0 ON LINE SENSOR WHITE
  // 1 MEANS BLACK
  // 20 VALUE OF CLOSE ENBEMY

  digitalWrite(ultraT, LOW);
  delayMicroseconds(5);
  digitalWrite(ultraT, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraT, LOW);
  
  duration = pulseIn(ultraE, HIGH);
  distance = duration*0.034/2;
     
  Serial.print("Distance:");
  Serial.println(distance);


  if (distance <= 20)
  {
   rotateL();
  }
  else {
    forward();
  }
  Serial.println(digitalRead(irL));
  
  Serial.println(digitalRead(irR));
 

  motorL.run(RELEASE);
  motorR.run(RELEASE);
  //delay(2000);




  //motor.run(RELEASE);
  //delay(100);
  //motor.run(BACKWARD);

  //motor.run(RELEASE);


}
void forward()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(100);
}

void rotateL()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(FORWARD);
  motorR.run(FORWARD);
  delay(300);
}

void rotateR()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(BACKWARD);
  motorR.run(BACKWARD);
  delay(300);
}
