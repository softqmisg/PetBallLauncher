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
int angle = 0;
void Servo_move(byte channel, int value)
{
    for (int angle = 0; angle <= value; angle +=1) {
     Servo_write(channel,angle); 
      delay(15);
  }
}
void setup() {
  // put your setup code here, to run once:

  pinMode(MOTOR1_PIN,OUTPUT);
  pinMode(MOTOR2_PIN,OUTPUT);
  pinMode(IR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(MOTOR1_PIN,HIGH); //turn M1 off
  digitalWrite(MOTOR2_PIN,HIGH); //turn M1 off

  digitalWrite(LED_PIN,LOW); //turn LED ON
  myservo1=Servo_attach(SERVO_PIN);


  }

void loop() {
    // Servo_write(myservo1,120);// ball Barrier back up
    // delay(1000);
    // Servo_write(myservo1,0);// ball Barrier back up
    // delay(1000);
    // Servo_write(myservo1,180);// ball Barrier back up
    // delay(1000);
    // Servo_write(myservo1,90);// ball Barrier back up
    // delay(1000);    
  // if(digitalRead(IR_PIN)==LOW)
  // {
  //   Servo_write(myservo1,90);// ball Barrier back up
  // }
  // else
  // {
  //   Servo_write(myservo1,0);// ball Barrier back up

  // }
  // put your main code here, to run repeatedly:
  if(digitalRead(IR_PIN)==LOW) //object  in front of IR
  {
    delay(DELAY_DETECTTOSTART);
     digitalWrite(LED_PIN,HIGH); //Turn off LED
    digitalWrite(MOTOR1_PIN,LOW);// turn motor1 On
    delay(DELAY_MOTOR2START);
    digitalWrite(MOTOR2_PIN,LOW);// turn motor2 On
    Servo_write(myservo1,180);// let ball to drop
    delay(DELAY_LAUNCHINGTIM);
    digitalWrite(MOTOR1_PIN,HIGH);// turn motor1 off
    digitalWrite(MOTOR2_PIN,HIGH);// turn motor1 off
    Servo_write(myservo1,0);// ball Barrier back up
    delay(DELAY_WAITBEFORENEXTROUND);
  }
  
 
}