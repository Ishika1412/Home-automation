#include<Servo.h>
int relay =13;
int data =0;
int pos=0;
Servo myservo;


void setup () {

pinMode (relay,OUTPUT);
digitalWrite (relay,OUTPUT);
Serial.begin(9600);
myservo.attach(9);
}

void loop ( ) {
  if (Serial.available())
  data =Serial.read ();
  if (data=='2')
  {
    digitalWrite (relay,HIGH);
    Serial.println("ON");
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);   // waits 15ms for the servo to reach the position
    
  }
  }
  else if (data == '7')
  {
    digitalWrite (relay,LOW);
    Serial.println("OFF"); 
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  
delay (50);
}
