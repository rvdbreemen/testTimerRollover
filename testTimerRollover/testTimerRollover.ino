/*
 * Author:  Willem Aandewiel
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the millis() RollOver debacle
 * I have made some _LOW macro's that are used with a semi millis()
 * Function wordt uint8_t (8 bit) timers so you don't have to wait
 * 49 day's before a RollOver occurs.
 * Just remove the 8Bit macro's if you want to use the safeTimers.h file
 * in your program.
 */

#include "safeTimers.h"

  DECLARE_TIMERms(every100ms, 100)      // update myTimer every 100 ms
  DECLARE_8BIT_TIMER(test8Bit, 15)  // print text every 15 timer8Bit() something

void printText()
{
  Serial.printf("[%02d:%02d:%03d] timer8Bit()[%6u], x_last[%6u]  ..\r\n", ((millis()/ (60 * 1000)) % 60)
                                                                        , ((millis() / 1000) % 60)
                                                                        , (millis() % 1000)
                                                                        , timer8Bit()
                                                                        , test8Bit_last);
}

void setup() {
   Serial.begin(115200);
   Serial.println("\n.. and then it begins ...\n");

}

void loop() {
  if ( DUE(every100ms))
  {
    myTimer++;
    Serial.print(".");
  }      
  if ( DUE_8BIT(test8Bit) ) {
      printText();
  }

}
