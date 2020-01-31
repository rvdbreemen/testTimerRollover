/*
 * Author:  Willem Aandewiel
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the millis() RollOver debacle
 * I have made some _LOW macro's that are used with a semi millis()
 * Function wordt uint8_t (8 bit) timers so you don't have to wait
 * 49 day's before a RollOver occurs.
 * Just remove the _LOW macro's if you want to use the timers.h file
 * in your program.
 */

static uint8_t myTimer = 0;

#include "timers.h"

  DECLARE_TIMERms(waiting, 50)          // update myTimer every 50 ms
  DECLARE_8BIT_TIMER(printTheText, 15)  // print text every 15 myTimer's

void printText()
{
  Serial.printf("myTimer[%6u], x_interval[%6u] x_last[%6u]  ..\r\n", myTimer, printTheText_interval, printTheText_last);
}

void setup() {
   Serial.begin(115200);
   Serial.println("\n.. and then it begins ...\n");

}

void loop() {
  if ( DUE(waiting))
  {
    myTimer++;
    Serial.print(".");
  }      
  if ( DUE_8BIT(printTheText) ) {
      printText();
  }

}
