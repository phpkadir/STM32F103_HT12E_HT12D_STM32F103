/*
 * \brief Receive data from wireless remote controller (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include "WirelessRemoteController.h"

WirelessRemoteController::WirelessRemoteController(bool transmitter,uint8 pin_D0, uint8 pin_D1, uint8 pin_D2, uint8 pin_D3)
{
  _pins[0] = pin_D0;
  _pins[1] = pin_D1;
  _pins[2] = pin_D2;
  _pins[3] = pin_D3;
  //_pins[6] = pin_TE;
  if(transmitter==false){
  for (int i = 0; i < 4; i++) {
    pinMode(_pins[i], INPUT);
	digitalWrite(_pins[i],LOW);
  }
  pinMode(PA8, INPUT);
  }
  else{
	for (int i = 0; i < 4; i++) {
    pinMode(_pins[i],OUTPUT_OPEN_DRAIN);
	
  }
  pinMode(PA8,OUTPUT_OPEN_DRAIN);
  digitalWrite(PA8,LOW);
  }
}

uint8 WirelessRemoteController::getCurrentValue()
{
  bool pino=0;
  uint8 gelen=0x00;
  for (int i = 0; i < 4; i++) {
    pino=digitalRead(_pins[i]);
	if(pino==HIGH){	gelen+=(1<<i); }
    
  }
  gelen=~gelen&0x0F;
  return gelen;
}

void WirelessRemoteController::sendCurrentValue(uint8 datam)
{
  bool is_valid = false;
  bool pinok=0;
  for (int i = 0; i < 4; i++) {
	pinok=datam&(1<<i); 
    if(pinok){ digitalWrite(_pins[i],LOW);}
	if(!pinok){ digitalWrite(_pins[i],HIGH);}
    is_valid |= pinok;
  }
  // digitalWrite(PA8,LOW);delay(200); digitalWrite(PA8,HIGH);
 // return is_valid;
}
void WirelessRemoteController::addTrigger(uint8 pin_DT, void (*function)())
{
  attachInterrupt(digitalPinToInterrupt(pin_DT), function, RISING);
}
