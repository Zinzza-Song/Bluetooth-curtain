#include<Servo.h>
#include<SoftwareSerial.h>

Servo s;
SoftwareSerial BT(11, 10);

int servoPin = 3;
int led = 13;
int flame = A0;
int val = 0;
int check = 2;

void setup() {

 pinMode(led, OUTPUT);
 pinMode(flame, INPUT);

 Serial.begin(9600);
 BT.begin(9500);
 s.attach(servoPin, 544, 2400);

}

void loop() {

     if(BT.available() > 0){

        char mode = BT.read();

        if(mode == '1')
          check = 1;
      
     }

     if(check == 1)
      blueOk();
     else
      blueNo();

}

void blueOk(){
  
  Serial.println("ON");
  char inChar = BT.read();

  if(inChar == '3'){

      s.write(0);
      digitalWrite(led, LOW);
      delay(1000);
    
  } else if(inChar == '4'){
      
      s.write(90);
      digitalWrite(led, HIGH);
      delay(1000);     
    
  } else if(inChar == '0')
    check = 2;
  
}

void blueNo(){

  val = analogRead(flame);
  Serial.println(val);
  Serial.println("OFF");

  if(val >= 600){
    
    s.write(0);
    digitalWrite(led, HIGH);
    delay(1000);
    
  } else {
    
    s.write(90);
    digitalWrite(led, LOW);
    delay(1000);
    
  } 
  
}

