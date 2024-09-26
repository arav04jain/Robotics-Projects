//Importing Servo Library for servo motor control
#include <Servo.h>


//Defining Servo Motors
Servo a;
Servo b;
Servo c;
Servo d;


//Storing Positions of Each Servo
int pos = 0;
int servoPos_a = 90;
int servoPos_b = 60;
int servoPos_c = 155;


//Button State variable
int buttonState_a_l;
int buttonState_a_r;

int buttonState_b_l;
int buttonState_b_r;

int buttonState_c_l;
int buttonState_c_r;


void setup() {
  //Attaching Servos to digital pins
  a.attach(11);
  b.attach(10);
  c.attach(9);
  d.attach(8);


  //Attaching buttons to digital pins
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(12, INPUT);

  //Defining Servos initial position
  a.write(90);
  b.write(60);
  c.write(155);
  d.write(0);
}

void loop() {

  //Getting button state from digital pin
  buttonState_a_l = digitalRead(7);

  //Checking if the button state is high
  if (buttonState_a_l == 1) {
    // variable stroing servo position decreased/increased
    servoPos_a = servoPos_a - 5;

    //if servo position exceeds the max and goes below the min, it'll remain the same
    if (servoPos_a < 0) {
      servoPos_a = 0;
    }

    //writing the position on the servo
    a.write(servoPos_a);
    delay(50);
  }

  buttonState_a_r = digitalRead(6);

  if (buttonState_a_r == 1) {
    servoPos_a = servoPos_a + 5;
    if (servoPos_a > 180) {
      servoPos_a = 180;
    }
    
    a.write(servoPos_a);
    delay(50);
  }

  buttonState_b_l = digitalRead(5);

  if (buttonState_b_l == 1) {
    servoPos_b = servoPos_b - 5;
    if (servoPos_b < 0) {
      servoPos_b = 0;
    }
    
    b.write(servoPos_b);
    delay(50);
  }

  buttonState_b_r = digitalRead(4);

  if (buttonState_b_r == 1) {
    servoPos_b = servoPos_b + 5;
    if (servoPos_b > 180) {
      servoPos_b = 180;
    }
 
    b.write(servoPos_b);
    delay(50);
  }



  buttonState_c_l = digitalRead(3);

  if (buttonState_c_l == 1) {
    servoPos_c = servoPos_c - 5;
    if (servoPos_c < 0) {
      servoPos_c = 0;
    }
    
    c.write(servoPos_c);
    delay(50);
  }

  buttonState_c_r = digitalRead(2);

  if (buttonState_c_r == 1) {
    servoPos_c = servoPos_c + 5;
    if (servoPos_c > 180) {
      servoPos_c = 180;
    }
 
    c.write(servoPos_c);
    delay(50);
  }

  //Checking touch sensor
  if (digitalRead(12) == HIGH) {

    //If touch sensor is high and the servo is 180, then it'll be turned to 0 and vica versa
    if (pos == 180) {
      d.write(0);
      pos = 0;
      delay(150);
    } else {
      d.write(180);
      pos = 180;
      delay(150);
    }
  }

}
