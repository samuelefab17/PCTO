#include <Scheduler.h>

int pin1 = 4u; //GP 4
int pin2 = 5u; //GP 5
int pin3 = 6u; //GP 6 
int pin4 = 7u; //GP 7

void setup() {

  Serial.begin(9600);
  //Serial.begin(115200);

  // Setup the 3 pins as OUTPUT
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);



  // Starting loops
  Scheduler.startLoop(loop2);
  Scheduler.startLoop(loop3);
  Scheduler.startLoop(loop4);
  Scheduler.startLoop(loop5);
  Scheduler.startLoop(loop6);

}

// Task n.1
void loop() {

 digitalWrite(pin1, HIGH);
 delay(0.1);
 digitalWrite(pin1, LOW);
 delay(0.1);

}

// Task n.2
void loop2() {

  digitalWrite(pin2, HIGH);
  delay(1);
  digitalWrite(pin2, LOW);
  delay(1);

}

// Task n.3
void loop3() {

  digitalWrite(pin3, HIGH);
  delay(10);
  digitalWrite(pin3, LOW);
  delay(10);

}

// Task n.4
void loop4(){

  digitalWrite(pin4, HIGH);
  delay(100);
  digitalWrite(pin4, LOW);
  delay(100);

}

// Task n.5
void loop5(){

 float number = 42.12743578; 
 float result = sqrt(number);
 delay(1000);

}

// Task n.6
void loop6(){
 
 int d = 60;
 int y = 56;
 int l = 5;
 int result;

 result = (d*l)/y;

 Serial.println(result);
 delay(1000);

 yield();
}

