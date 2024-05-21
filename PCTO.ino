
#include <Scheduler.h>
//##################### PIN ######################

 int pin1 = 4u; //GP 4
 int pin2 = 5u; //GP 5
 int pin3 = 6u; //GP 6 
 int pin4 = 7u; //GP 7

//################## START SERIAL ################

 #define BEGIN 1

//################## START LOOP #################

 #define LOOP2 1
 #define LOOP3 1
 #define LOOP4 1
 #define LOOP5 1
 #define LOOP6 1
 #define LOOP7 1

//################### LOOP TIME ##################

//Loop time of task n.1
 #define LOOP1_TIME 100    
//Loop time of task n.2
 #define LOOP2_TIME 100
//Loop time of task n.3    
 #define LOOP3_TIME 100  
//Loop time of task n.4
 #define LOOP4_TIME 100      
//Loop time of task n.5 
 #define LOOP5_TIME 1000 
//Loop time of task n.6 
 #define LOOP6_TIME 1001   

//################# FUNCTION PIN #################

void function_pin(int pin, int LOOP_TIME) {
  digitalWrite(pin, HIGH);
  delay(LOOP_TIME);
  digitalWrite(pin, LOW);
  delay(LOOP_TIME);
}

//################### SET UP #####################
void setup() {
  
//######### SETUP THE 4 PINS AS OUTPUT ###########

   pinMode(pin1, OUTPUT);
   pinMode(pin2, OUTPUT);
   pinMode(pin3, OUTPUT);
   pinMode(pin4, OUTPUT);
  
//##################### BEGIN ####################

   #if BEGIN9600 == 0
     Serial.begin(9600);
   #endif

   #if BEGIN115200 == 1
     Serial.begin(115200);
   #endif

//##################### LOOP #####################

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

   #if LOOP7 == 1
     Scheduler.startLoop(loop7);
   #endif

}

// Task n.1
void loop() {

   function_pin(pin1, LOOP1_TIME);

}

// Task n.2
void loop2() {

   function_pin(pin2, LOOP2_TIME);

}

// Task n.3
void loop3() {

   function_pin(pin3, LOOP3_TIME);

}

// Task n.4
void loop4(){

   function_pin(pin4, LOOP4_TIME);

}

// Task n.5
void loop5(){

   float number1_LOOP5 = random(99999) / 100000.0;
   float number2_LOOP5 = random(99999) / 1000.0;
   float number3_LOOP5 = random(99999) / 10000.0;
   float number4_LOOP5 = random(99999) / 1000.0;

   double result1_LOOP5 = (number1_LOOP5 * number4_LOOP5) / (number2_LOOP5 * number3_LOOP5);
   double result2_LOOP5 = sqrt(result1_LOOP5);
   Serial.println(result1_LOOP5);

   delay(LOOP5_TIME);

   yield();

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
    
   double result1_LOOP6 = (number1_LOOP6 * number3_LOOP6) / number2_LOOP6;
   double result2_LOOP6 = sqrt(result1_LOOP6) + number4_LOOP6;

   Serial.println(result2_LOOP6);

   delay(LOOP6_TIME);

   yield();

}
void loop7(){

   digitalWrite(LED_BUILTIN, HIGH);
   delay(10000);
   digitalWrite(LED_BUILTIN, LOW);
   delay(100);
   
   yield();

}