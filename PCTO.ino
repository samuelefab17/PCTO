
#include <Scheduler.h>
//##################### PIN ######################

int pin1 = 4u; //GP 4
int pin2 = 5u; //GP 5
int pin3 = 6u; //GP 6 
int pin4 = 7u; //GP 7

//################## START SERIAL ################

#define BEGIN9600 1
#define BEGIN115200 0

//################### START LOOP #################

#define LOOP2 1
#define LOOP3 1
#define LOOP4 1
#define LOOP5 1
#define LOOP6 1

//#################### LOOP TIME ##################

//Loop time of task n.1
#define LOOP_TIME 100      
//Loop time of task n.2
#define LOOP2_TIME 100  
//Loop time of task n.3    
#define LOOP3_TIME 100      
//Loop time of task n.4
#define LOOP4_TIME 100      
//Loop time of task n.5 and n.6
#define LOOP5e6_TIME 100    

void setup() {
  
//######### SETUP THE 4 PINS AS OUTPUT ###########

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
//########### BEGIN ##########

  #if BEGIN9600 == 1
    Serial.begin(9600);
  #endif

  #if BEGIN115200 == 1
    Serial.begin(115200);
  #endif

//########## LOOP ##########

  #if LOOP2 == 1
    Scheduler.startLoop(loop2);
  #endif

  #if LOOP3 == 1
    Scheduler.startLoop(loop3);
  #endif

  #if LOOP4 == 1
    Scheduler.startLoop(loop4);
  #endif

  #if LOOP5 == 1
    Scheduler.startLoop(loop5);
  #endif

  #if LOOP6 == 1
    Scheduler.startLoop(loop6);
  #endif

}

// Task n.1
void loop() {

 digitalWrite(pin1, HIGH);
 digitalWrite(LED_BUILTIN, HIGH);
 delay(LOOP_TIME);
 digitalWrite(pin1, LOW);
 digitalWrite(LED_BUILTIN, LOW);
 delay(LOOP_TIME);

}

// Task n.2
void loop2() {

  digitalWrite(pin2, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LOOP2_TIME);
  digitalWrite(pin2, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LOOP2_TIME);

}

// Task n.3
void loop3() {

  digitalWrite(pin3, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LOOP3_TIME);
  digitalWrite(pin3, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LOOP3_TIME);

}

// Task n.4
void loop4(){

  digitalWrite(pin4, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LOOP4_TIME);
  digitalWrite(pin4, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LOOP4_TIME);

}

// Task n.5
void loop5(){

 float number1_LOOP5 = random(99999) / 100000.0;
 float number2_LOOP5 = random(99999) / 1000.0;
 float number3_LOOP5 = random(99999) / 10000.0;
 float number4_LOOP5 = random(99999) / 1000.0;

 float result1_LOOP5 = (number1_LOOP5 * number4_LOOP5) / (number2_LOOP5 * number3_LOOP5);
 float result2_LOOP5 = sqrt(result1_LOOP5);

 delay(LOOP5e6_TIME);

}

// Task n.6
void loop6(){
 
 int number1_LOOP6;
 int number2_LOOP6;
 int number3_LOOP6;
 int number4_LOOP6;

 number1_LOOP6 = random(9999);
 number2_LOOP6 = random(9999);
 number3_LOOP6 = random(9999);
 number4_LOOP6 = random(9999);
    
  
 float result1_LOOP6 = (number1_LOOP6 * number3_LOOP6) / number2_LOOP6;
 float result2_LOOP6 = sqrt(result1_LOOP6) + number4_LOOP6;

 Serial.println(result2_LOOP6);

 delay(LOOP5e6_TIME);

 yield();

}