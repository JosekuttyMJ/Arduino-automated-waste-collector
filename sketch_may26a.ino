#include <Servo.h>
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
int IRSensor = 3; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 



void setup() 
  {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode (IRSensor, INPUT); // sensor pin INPUT
    pinMode (LED, OUTPUT); // Led pin OUTPUT
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object   
  }

void loop() 
  {
  //collect distance
 int x=ultrasound(); 
 if (x>10)
   {
     forward();
     delay(500);
     int y=detect();//calling IR sensor function to return yes/no
     if(y=1)
     {
       servos();
     }
     
   }
 else
  {
    right();
    delay(50);
    forward();
    delay(50);
    right();
    delay(50);
   stopmotion();
  } 
 

}
/////////////////////////////////////////////////////////////
void servos()
{
 int pos = 0;    // variable to store the servo position 
   for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 90 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 90; pos>=1; pos-=1)     // goes from 90 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
}
int detect()
 {
   int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1)
  {
    digitalWrite(LED, LOW); // LED LOW
  }
  
  else
  {
    digitalWrite(LED, HIGH); // LED High
  }
  return statusSensor;
 }
int ultrasound()
 {
  // defines variables
long duration;
int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  return distance;
  //return distance in cm
}

void forward()
{ 
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
}//forward

void right()
{
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}//towards right

void stopmotion()
{
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}//stop

void backward()
{
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}//backward

void left()
{
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}//left


