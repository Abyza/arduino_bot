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
  delay(5000);

 



}

void loop() {
  avoid();

}

void avoid(){
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
      
    backward();
    rotateL();
    //spin();
  }
  forward();
}
void sumo(){

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
     
  //Serial.print("Distance:");
  //Serial.println(distance);
  if(digitalRead(irL)== 0 && digitalRead(irR)== 0){
    backward();
    //spin();
  }
  if(digitalRead(irR)== 0){
    rotateL();
  }
  if(digitalRead(irL)== 0){
    rotateR();
  }
  if(digitalRead(irL)== 1 && digitalRead(irR)== 1){
    forward();
    if (distance <= 20)
    {
      forward();
      forward();
      //spin();
    }
  }
  //Serial.println(digitalRead(irL));
 // Serial.println(digitalRead(irR));
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(100);
}

void forward()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(100);
}

void backward()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(300);
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

void spin()
{
  //When we want to let Motor To Rotate ,
  // just  void this part on the loop section .
  motorL.run(BACKWARD);
  motorR.run(BACKWARD);
  delay(1000);
}
