#include <Scheduler.h>

//################### PIN ####################

int pin1 = 4u; //GP 4
int pin2 = 5u; //GP 5
int pin3 = 6u; //GP 6 
int pin4 = 7u; //GP 7

//#################### LOOPS TIME ##################

const int LOOP_TIME = 0.1;
const int LOOP2_TIME = 1;
const int LOOP3_TIME = 10;
const int LOOP4_TIME = 100;
const int LOOP5e6_TIME = 1000;

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
 delay(LOOP_TIME);
 digitalWrite(pin1, LOW);
 delay(LOOP_TIME);

}

// Task n.2
void loop2() {

  digitalWrite(pin2, HIGH);
  delay(LOOP2_TIME);
  digitalWrite(pin2, LOW);
  delay(LOOP2_TIME);

}

// Task n.3
void loop3() {

  digitalWrite(pin3, HIGH);
  delay(LOOP3_TIME);
  digitalWrite(pin3, LOW);
  delay(LOOP3_TIME);

}

// Task n.4
void loop4(){

  digitalWrite(pin4, HIGH);
  delay(LOOP4_TIME);
  digitalWrite(pin4, LOW);
  delay(LOOP4_TIME);

}

// Task n.5
void loop5(){

 float number = 42.12743578; 
 float numbertwo = 11.546238;
 float firstresult = sqrt(number);
 float secondresult = firstresult / numbertwo;
 delay(LOOP5e6_TIME);

}

// Task n.6
void loop6(){
 
 int d = 60;
 int y = 56;
 int l = 5;
 int result;

 result = (d*l)/y;

 Serial.println(result);
 delay(LOOP5e6_TIME);

 yield();
}

