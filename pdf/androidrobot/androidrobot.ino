#include <AFMotor.h>              // download this library from https://github.com/adafruit/Adafruit-Motor-Shield-library/zipball/master (Still available as of 31st January 2017)
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A2, A3);  // Connect the TXD pin of BT module to pin A2 of the Arduino (or the L293D motor shield). The RXD pin of BT module and A3 of Arduino can be left unconnected.

AF_DCMotor motor1(1, MOTOR12_64KHZ); // Left motor 1
AF_DCMotor motor2(2, MOTOR12_64KHZ); // Left motor 2
AF_DCMotor motor3(3, MOTOR12_64KHZ); // Right motor 1
AF_DCMotor motor4(4, MOTOR12_64KHZ); // Right motor 2

signed int x;
signed int y;
signed int z;
signed int w;

float a;
float m;

String str;
char dir = 0;

int el = 0;
int er = 0;

int elp = 0;
int erp = 0;

char getData;

boolean fast = true;
boolean StateA0 = false;
boolean StateA1 = false;
boolean State11 = false;

void process();
void processa();
void processb();
void processc();
void processx();
void processy();
void processz();
void processM();
void processA();

void setup() {
  
  mySerial.begin(9600);
  mySerial.println("Start...");
  Serial.begin(9600);
  Serial.println("Start...");  
}


void loop() 
{

    
    while(mySerial.available())
    {

      char getData = mySerial.read();

        if (getData == 'M')
        {
          m = mySerial.parseFloat();
          
          if (mySerial.read() == '#') 
          {
            processM();
          }
        }
        
        if (getData == 'A')
        {
          a = mySerial.parseFloat();
          
          if (mySerial.read() == '#') 
          {
            processA();
          }
        }
       
        if (getData == 'a')
        {  
          delay(5);        
          if (mySerial.read() == '#') 
          {
            processa();
          }
        }      
       
        if (getData == 'b')
        {    
          delay(5);
          if (mySerial.read() == '#') 
          {
            processb();
          }
        }   

        if (getData == 'c')
        {     
          delay(5);
          if (mySerial.read() == '#') 
          {
            processc();
          }
        } 

        if (getData == 'x')
        {  
          delay(5);        
          if (mySerial.read() == '#') 
          {
            processx();
          }
        }      
       
        if (getData == 'y')
        {    
          delay(5);
          if (mySerial.read() == '#') 
          {
            processy();
          }
        }   

        if (getData == 'z')
        {     
          delay(5);
          if (mySerial.read() == '#') 
          {
            processz();
          }
        } 
       
        if (getData == '~') {
        
          x = mySerial.parseInt();
        
            if (mySerial.read() == '*') {
        
              y = mySerial.parseInt();
        
                if (mySerial.read() == '@') {
                
                  z = mySerial.parseInt();
                  
                    if (mySerial.read() == '.') {
                      
                      w = mySerial.parseInt();
                      
                        if (mySerial.read() == '#') {
                          
                          process();
                        }
                  }                
              } 
           }
        }
        
          
        
    }
    
}

void process() {
      
  Serial.print("x: " + String(x) + ", y: " + String(y) + ", z: " + String(z) + ", w: " + String(w));

  //Use the x, y, z and w values as you wish here.

  if (fast == false) { er = map(y, 0, 255, 0, 255); }
  else { er = y; }

  if (er >= 0) { //>=
    motor1.run(FORWARD);     
    motor2.run(FORWARD);
    Serial.println(", Motor 1 & 2 Forward");
  } 
  
  else if (er < 0) { //<
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    Serial.println(", Motor 1 & 2 Backward");
  } 
  
  erp = abs(er);
  

//right motor control:

  if (fast == false) { el = map(x, 0, 255, 0, 255); }
  else { el = x; }

  if (el > 0) { //>
    motor3.run(BACKWARD);     
    motor4.run(BACKWARD);
    Serial.println(", Motor 3 & 4 Backward");
  } 
  
  else if (el <= 0)  { //<=
    motor3.run(FORWARD);      
    motor4.run(FORWARD);
    Serial.println(", Motor 3 & 4 Forward");
  } 
  
  elp = abs(el);
                                                 
  motor1.setSpeed(elp);    
  motor2.setSpeed(elp);  
  
  motor3.setSpeed(erp);   
  motor4.setSpeed(erp);    
  
  Serial.flush(); 
  mySerial.flush();   
}  

void processa(){
  Serial.println("Button a! ");
  StateA0 = !StateA0;
  if (StateA0 == true) { digitalWrite(A0, HIGH); } else { digitalWrite(A0, LOW); }
  mySerial.flush();  
}

void processb(){
  Serial.println("Button b! "); 
  State11 = !State11;
  if (State11 == true) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
  mySerial.flush(); 
}

void processc(){
  Serial.println("Button c! ");
  StateA1 = !StateA1;
  if (StateA1 == true) { digitalWrite(A1, HIGH); } else { digitalWrite(A1, LOW); }
  mySerial.flush();  
}

void processx(){
  Serial.println("Button x! "); 
  mySerial.flush(); 
  fast = true;
}

void processy(){
  Serial.println("Button y! "); 
  mySerial.flush(); 
}

void processz(){
  Serial.println("Button z! "); 
  mySerial.flush(); 
  fast = false;
}

void processM(){
  Serial.print("Received Magnitude: ");
  Serial.println(m); 
  mySerial.flush();   
}

void processA(){
  Serial.print("Received Angle: ");
  Serial.println(a); 
  mySerial.flush();   
}


