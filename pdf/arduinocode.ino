/**
 * Arduino Code for line following and obstracle avoidance robot using IR and Ultrasonic sensor
 * Done by Abhishek B (www.abhishekbalu.com)
 * for more information contact : Abhisheklokesh6008@gmail.com
 */
 
#include <Servo.h>   //include servo library 
Servo servo ; 
const int pingPin = 11; 
   long duration; 
   long cm ;
int a = 4;
int b = 7;
int c = 8;
int d = 12;
int e = 13;
int x;
int y;
int z;
int l;
int m;
int hoba;
int in=0;
int en1 =5;
int en2 =6;
int in1 =A1;
int in2 =A2;
int in3 =A3;
int in4 =A4;
int tilt=A0;
int spd=150;
int spod=250;
int n=3;
int t1;
int t2;
int tt;
int inlast;
int counter=0;
void setup(){
 pinMode(en1,OUTPUT);
 pinMode(en2,OUTPUT);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT); 
 Serial.begin(4800); // 4800 used instead of 9600 {Because transmission rate in 9600 is faster than 4800 in communication }
 servo.write(90); //servo angle set to look forward
  servo.attach(9); // pin attached to microcontroller
f1();

}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void fp(){
  digitalWrite(in1, HIGH); // motor 1 power on forward  
  digitalWrite(in3, HIGH); // motor 2 power on forward
  analogWrite(en1,255); // enable1 is on with full power
  digitalWrite(in2,LOW); // motor 2 power off backward
  digitalWrite(in4,LOW); // motor 2 power off backward 
  analogWrite(en2,255); // enable2 is on with full power 
}
void f1(){
  digitalWrite(in1, HIGH); // motor 1 power on forward  
  digitalWrite(in3, HIGH); // motor 2 power on forward
  analogWrite(en1,100); // enable1 is on with full power
  digitalWrite(in2,LOW); // motor 2 power off backward
  digitalWrite(in4,LOW); // motor 2 power off backward 
  analogWrite(en2,100); // enable2 is on with full power 
}

 void f2()
 {
   digitalWrite(in1, HIGH); // motor 1 power on forward 
  digitalWrite(in3, HIGH); // motor 2 power on forward 
  analogWrite(en1,100); // enable1 is on with weak power 
  digitalWrite(in2,LOW); // motor 2 power off backward
  digitalWrite(in4,LOW); // motor 2 power off backward
  analogWrite(en2,90); // enable2 is on with weaker power {For controlling direction}  
 }


void fc(){
   digitalWrite(in1, HIGH); // motor 1 power on forward 
  digitalWrite(in3, HIGH); // motor 2 power on forward 
  analogWrite(en1,220); // enable1 is on
  digitalWrite(in2,LOW); // motor 2 power off backward
  digitalWrite(in4,LOW); // motor 2 power off backward
  analogWrite(en2,130); // enable2 is on with weaker power {For controlling direction}
}
void f3(){ 
   digitalWrite(in1, HIGH ); // motor 1 power on forward 
  digitalWrite(in3, HIGH  ); // motor 2 power on forward 
  analogWrite(en1,90  ); // enable1 is on with weak power 
  digitalWrite(in2,LOW  );  // motor 1 power off backward 
    digitalWrite(in4,LOW );  // motor 2 power off backward 
  analogWrite(en2,100 ); // enable2 is on with weaker power {For controlling direction}
  
}
void f4(){
  digitalWrite(in1, HIGH); // motor 1 power on forward 
  digitalWrite(in3, HIGH); // motor 2 power on forward 
  analogWrite(en1,0); // enable1 is off 
  digitalWrite(in2,LOW);  // motor 1 power off backward 
  digitalWrite(in4,LOW);  // motor 2 power off backward 
  analogWrite(en2,100); // enable2 is on with weak power {middle power for normal line tracking}

}
void f9(){
  digitalWrite(in1, HIGH); // motor 1 power on forward 
  digitalWrite(in3, HIGH); // motor 2 power on forward 
  analogWrite(en1,0); // enable1 is off 
  digitalWrite(in2,LOW);  // motor 1 power off backward 
  digitalWrite(in4,LOW);  // motor 2 power off backward 
  analogWrite(en2,150); // enable2 is on with full power 

}


void f5(){  
  digitalWrite(in1, HIGH); // motor 1 power on forward 
  digitalWrite(in3, HIGH); // motor 2 power on forward 
  analogWrite(en1,100); // enable1 is on with weak power {middle power for normal line tracking}
  digitalWrite(in2,LOW); // motor 1 power on backward 
  digitalWrite(in4,LOW); // motor 2 power on backward 
  analogWrite(en2,0); // enable2 is off
}  
 
void f6(){
 digitalWrite(in1, LOW); // motor 1 power on forward
  digitalWrite(in3, LOW); // motor 2 power on forward
  analogWrite(en1,0); // enable1 is off 
  digitalWrite(in2,LOW); // motor 1 power on backward
  digitalWrite(in4,LOW); // motor 2 power on backward
  analogWrite(en2,0); // enable2 is off
}

void ymen(){
digitalWrite(in1, LOW); // motor 1 power off forward
  digitalWrite(in3, HIGH); // motor 2 power on forward
  analogWrite(en1,120); // enable1 is on
  digitalWrite(in2,HIGH);  // motor 1 power on backward
  digitalWrite(in4,LOW);  // motor 2 power off backward
  analogWrite(en2,130); // enable2 is on
}

void shmal(){
digitalWrite(in1, HIGH); // motor 1 power on forward
  digitalWrite(in3, LOW); // motor 2 power off forward
  analogWrite(en1,120); // enable1 is on
  digitalWrite(in2,LOW); // motor 1 power off backward
  digitalWrite(in4,HIGH); // motor 2 power on backward
  analogWrite(en2,130); // enable1 is on
}

void backward(){
 digitalWrite(in1, LOW); // motor 1 power off forward
  digitalWrite(in3, LOW); // motor 1 power off forward
  analogWrite(en1,110); // enable1 is on  
  digitalWrite(in2,HIGH); // motor 1 power on backward
  digitalWrite(in4,HIGH); // motor 2 power on backward
  analogWrite(en2,110); // enable1 is on
}
 void set () {
 if(digitalRead(a)== 1){x=16;}else{x=0;} // if the light sensor a falls on black line it uses binary method
 if(digitalRead(b)== 1){ y=8;}else{y=0;} // if the light sensor b falls on black line it uses binary method
 if(digitalRead(c)== 1){ z=4;}else{z=0;} // if the light sensor c falls on black line it uses binary method
 if(digitalRead(d)== 1){ l=2;}else{l=0;} // if the light sensor d falls on black line it uses binary method
 if(digitalRead(e)== 1){ m=1;}else{m=0;} // if the light sensor e falls on black line it uses binary method
 hoba =x+y+z+l+m; // save all values in one variabale of light sensors
           
 }
void e2ra () {

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.println(cm);
delay(10);
}


void loop(){ 
  e2ra();
    
 e2ra(); // call function e2ra
 if (cm<=4) {    // if the distance less than or equal 10    
   servo.write(90); // change the servo to 90 degree angle.
do {
  
  backward(); // Make the function Backward instantly
  e2ra();         // Make the function e2ra instantly
  
} while (cm<=15);  // check the condition if true repeat the loop if not get out
e2ra(); // do e2ra function
servo.write(80);
do { f4(); // do f4 function instantly
e2ra(); // do e2ra function
servo.write(80);

 } while (cm<=25); // check the condition if true repeat the loop if not get out
do {
  f1(); // do f1 function instantly 
e2ra(); // do e2ra function instantly
servo.write(10); // change the servo to 180 degree angle.
 
 } while(cm>=20); // check the condition if true repeat the loop if not get out 
 
 f6(); // do e2ra function
 delay(100); // wait for 100 millisec.
 do {
   f1(); // do f1 function instantly
   e2ra(); // do e2ra function instantly
 } while(cm<30); // check the condition if true repeat the loop if not get out
 
 do {
   f5(); // do f5 function instantly
   e2ra(); // do e2ra function instantly
 } while (cm>25); // check the condition if true repeat the loop if not get out
 
 do {
   f1 (); // do f1 function instantly
   e2ra(); // do e2ra function instantly
 } while (cm<30); // check the condition if true repeat the loop if not get out
 
do { f6(); } while(cm>30);

 }
 


  
  else if(cm>10){
x:
  set(); // call function set
if     (hoba==1) {ymen();}        
else if(hoba==2) {f3();}
else if(hoba==3) {ymen();}
else if(hoba==6) {f3();}
else if(hoba==4) {n=0; f1();}
else if(hoba==12){f2();} 
else if(hoba==24){shmal();}
else if(hoba==8) {f2();}
else if(hoba==16){shmal();}

else if(hoba==7) {ymen();}
else if(hoba==28){shmal();}

else if(hoba==31){

while(hoba==31||hoba==7||hoba==15||hoba==28||hoba==30){  set();f1();}

while(digitalRead(e)==1){ymen();}
while(digitalRead(e)!=1){ymen();}
while(digitalRead(c)!=1){ymen();}
while(digitalRead(c)==1){goto x;}
}// for every condition of the past conditions  call a pre-defined function
 


}
}
