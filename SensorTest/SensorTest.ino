#include <Servo.h>

#include <Adafruit_MotorShield.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int dir = 0;
int dir_mag = 20;

const int pot    = A0;
const int sensor = A1;
const int button = 7;

int button_state =0;
int sensor_reading;
int pot_reading;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT_PULLUP);
  pinMode(pot,INPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button);
  sensor_reading = analogRead(sensor);
  pot_reading = analogRead(pot);
  Serial.println(" ");
  Serial.print("Button: ");
  Serial.print(button_state);    
  Serial.print("  sensor: ");
  Serial.print(sensor_reading);
  Serial.print("  pot: ");
  Serial.print(pot_reading);
  Serial.print("  pos: ");
  Serial.print(pos);

  if(pos>180){dir = -dir_mag;}
  if(pos<1){dir = dir_mag;}
  pos = pos+dir;
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //delay(15);                       // waits 15ms for the servo to reach the position
}


