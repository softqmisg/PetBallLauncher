#include <Arduino.h>
#include <Servo.h>
#define MOTOR1_PIN  PC6
#define MOTOR2_PIN  PC7
#define SERVO_PIN   PD4
#define IR_PIN      PC4
#define LED_PIN     PC3

#define DELAY_DETECTTOSTART 3000
#define DELAY_MOTOR2START   500
#define DELAY_LAUNCHINGTIM  1000
#define DELAY_WAITBEFORENEXTROUND  100

Servo myservo1;
void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR1_PIN,OUTPUT);
  pinMode(MOTOR2_PIN,OUTPUT);
  pinMode(IR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);


  myservo1=Servo_attach(PD3);
  Servo_write(myservo1,0); //go to position of 0
  digitalWrite(LED_PIN,LOW); //turn LED on
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(IR_PIN)==LOW) //object  in front of IR
  {
    delay(DELAY_DETECTTOSTART);
    digitalWrite(MOTOR1_PIN,LOW);// turn motor1 On
    delay(DELAY_MOTOR2START);
    digitalWrite(MOTOR2_PIN,LOW);// turn motor2 On
    Servo_write(myservo1,180);// let ball to drop
    delay(DELAY_LAUNCHINGTIM);
    digitalWrite(MOTOR1_PIN,HIGH);// turn motor1 off
    digitalWrite(MOTOR2_PIN,HIGH);// turn motor1 off
    Servo_write(myservo1,180);// ball Barrier back up
    delay(DELAY_WAITBEFORENEXTROUND);
  }

}