/*
 * \brief Get data from wireless remote controller asynchronously (interrupts)
 *
 * \This example is using the trigger signal from the remote controller to
 * asynchronously launch a function every time a data is received.
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \WirelessRemoteController library from its modified for ht12e/ht12d
 * \this code only have an example. 
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0 to use operating without serial clean serial codes..
 */

#include <WirelessRemoteController.h>

// Create wireless remote controller instance with D3, D4, D5, D6 pins as data pins
// B12,B13,B14,B15,A8,A9//TE=PA8
bool transmitteri=false;
//bool receiveri=true;
WirelessRemoteController remote_controller(transmitteri,PB12,PB13,PB14,PB15);
//WirelessRemoteController remote_controller(false,25,26,27,28,29,30);
int n; bool current_tx[4]; uint8 current_rx=0x00;
void receiveFromRemoteController(){
     current_rx=remote_controller.getCurrentValue();
    Serial.print("Data received: ");
    Serial.print(current_rx);  
    Serial.print("\n");
    //digitalWrite(LED_BUILTIN, HIGH);   // set the LED on
     delay(100);             // wait for a second
   // digitalWrite(LED_BUILTIN, LOW);    // set the LED off
  
}

void setup(void)
{
   // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  if(transmitteri==false){
   Serial.begin(9600);//remove if without pc serial need debugs
  
  while (!Serial)//remove if without pc serial need debugs
  {
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN)); // Turn the LED from off to on, or on to off //remove if without pc serial need debugs
    delay(100);         // fast blink//remove if without pc serial need debugs
  }
  Serial.println("Hello people");//remove if without pc serial need debugs
  }
  if(transmitteri==false){// Trigger interrupt by putting D2 pin as DT remote controller pin (trigger)
  remote_controller.addTrigger(PA8, receiveFromRemoteController);
  
  Serial.print("Data received from remote controller will be printed when received.\n");//remove if without pc serial need debugs
  }
}
void FromByte(uint8 c, bool b[6])
{
    for (int i=0; i < 6; ++i)
        b[i] = (c & (1<<i)) != 0;
 //return b;
}
void loop()
{
  //digitalWrite(LED_BUILTIN, HIGH);   // set the LED on
  //delay(500);              // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // set the LED off
  //Serial.print("Loop #: ");
  n++; 
  if(n>16){n=0;}
if(transmitteri==true){ 
  remote_controller.sendCurrentValue(n);
   //  Serial.print("Data Sent: ");    
   //   Serial.print(n);    
  //  Serial.print("\n");
 
   digitalWrite(LED_BUILTIN, HIGH);   // set the LED on
    delay(300);             // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // set the LED off
}

}
