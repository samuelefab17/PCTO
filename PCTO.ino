#include <Scheduler.h>
#include "MPU9250.h"

float acce[12];
float magn[12];

int acce_index;
int magn_index;

float ris_acce;
float ris_magn;

MPU9250 mpu;

//#define SERIAL_BAUD 9600
#define SERIAL_BAUD 115200

#define SERIAL_BAUD_COMMUNICATION 9600 //GP 0
//#define SERIAL_BAUD_COMMUNICATION 115200

#define LOOP2 1
#define LOOP3 1
#define LOOP4 1
#define LOOP5 0
#define LOOP6 0
#define KEEP_ALIVE 1

#define LOOP1_TIME 100 //ms
#define LOOP2_TIME 1000  
#define LOOP3_TIME 100  
#define LOOP4_TIME 1000       
#define LOOP5_TIME 1000 
#define LOOP6_TIME 2000

#define ELEM 10 //divisore

void setup() 
{
  Serial.begin(SERIAL_BAUD);
  Serial1.begin(SERIAL_BAUD_COMMUNICATION);

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

  #if KEEP_ALIVE == 1
    Scheduler.startLoop(keep_alive);
  #endif

  Wire.begin();
  mpu.setup(0x68);

  if (!mpu.setup(0x68)) 
  {  
    while (1) 
    {
      Serial.println("MPU connection failed.");
      delay(5000);
    }
  }
    mpu.verbose(true); 
    mpu.calibrateAccelGyro();
    delay(2500);
    mpu.calibrateMag();
    delay(500);
    mpu.verbose(false);
}

// Task n.1
void loop() 
{
  if (mpu.update())
  {
    static uint32_t prev_ms = millis();
    if (millis() > prev_ms + LOOP1_TIME) 
    {
      float lett = mpu.getMagX();
      float let = mpu.getAccZ();
      acce[acce_index] = let;
      magn[magn_index] = lett;
      acce_index++;
      magn_index++;
      prev_ms = millis();
    }    
  }
}
        
// Task n.2
void loop2() 
{
  float sum;
  if(acce_index == (ELEM - 1))
  {
    for (int i = 0; i < ELEM; i++)	
		 sum = sum + acce[i];
	  ris_acce = sum /ELEM;
    sum = 0;
    acce_index = 0;
  }
  delay(10);
}

// Task n.3
void loop3() 
{
  float sum;
  if(magn_index == (ELEM - 1))
  {
    for (int i = 0; i < ELEM; i++)	
		  sum = sum + magn[i];
	  ris_magn = sum /ELEM;
    sum = 0;
    magn_index = 0;
  }
  delay(10);
}

// Task n.4
void loop4()
{
  Serial1.print(ris_acce);
  Serial1.print(" ");
  Serial1.println(ris_magn);
  delay(LOOP4_TIME);
}

// Task n.5
void loop5()
{

}

// Task n.6
void loop6()
{

}

// Task n.7
void keep_alive()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);

  yield();
}