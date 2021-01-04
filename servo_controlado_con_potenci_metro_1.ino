#include <Servo.h>

Servo myservo;  


int potpin = 0;  
int val;  
int ang;
 

void setup() {
  myservo.attach(9); 
}

 

void loop() {
  val = analogRead(potpin); 
  Serial.print("Valor de portenciometro: ");
  Serial.println(val);
  ang = map(val, 0, 1023, 0, 180);     
  myservo.write(ang);                  
  delay(15);                           
}