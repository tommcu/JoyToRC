#include <Usb.h>
#include <usbhub.h>
#include <hid.h>
#include <hiduniversal.h>

#include <outputchannel.h>
#include <PPMOut.h>
#include <Timer1.h>

#define CHANNELS 4

#include "hidjoystickrptparser.h"

USB                                             Usb;
USBHub                                          Hub(&Usb);
HIDUniversal                                    Hid(&Usb);
JoystickEvents                                  JoyEvents;
JoystickReportParser                            Joy(&JoyEvents);

//rc::PPMOut ppm_out(CHANNELS);
//int test = 0;

void setup() {
  Serial.begin( 115200 );
  Serial.println("Starting Joy2RC - Initiating JoyStick USBHOST");

  if (Usb.Init() == -1)
      Serial.println("OSC did not start.");
      
  delay( 200 );

  if (!Hid.SetReportParser(0, &Joy))
      Serial.println("oooohhhh shhiiiitttt");
  //    ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1);
/*
  //rc::Timer1::init();
  
  //for (uint8_t i = 0;  i < CHANNELS; ++i)
  //{
  //  rc::setOutputChannel(static_cast<rc::OutputChannel>(i), 1500);
  //}

  ppm_out.setPulseLength(250);
  ppm_out.setPauseLength(15000);
  ppm_out.start(8); // pin 9 or 10 are preferred, but out of the question due to USB Shield
*/
}

void loop() {
  Usb.Task();
  
  /*rc::setOutputChannel(static_cast<rc::OutputChannel>(0), map(JoyEvents.X, 0, 0xFF, 1000, 2000));
  rc::setOutputChannel(static_cast<rc::OutputChannel>(1), map(JoyEvents.Y, 0, 0xFF, 1000, 2000));
  rc::setOutputChannel(static_cast<rc::OutputChannel>(2), map(JoyEvents.Z, 0, 0xFF, 1000, 2000));
  rc::setOutputChannel(static_cast<rc::OutputChannel>(3), map(JoyEvents.Rz, 0, 0xFF, 1000, 2000));
  ppm_out.update();*/
  
  Serial.println(JoyEvents.X);
  Serial.println(JoyEvents.Y);
  Serial.println(JoyEvents.Z);
  delay(200);
}
