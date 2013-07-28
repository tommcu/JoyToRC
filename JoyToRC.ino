#include <Usb.h>
#include <usbhub.h>
#include <hid.h>
#include <hiduniversal.h>

#include <PPMOut.h>
#include <Timer1.h>

#define CHANNELS 4

#include "hidjoystickrptparser.h"

USB                                             Usb;
USBHub                                          Hub(&Usb);
HIDUniversal                                    Hid(&Usb);
JoystickEvents                                  JoyEvents;
JoystickReportParser                            Joy(&JoyEvents);

uint16_t ppm_input[CHANNELS];
uint8_t ppm_work[PPMOUT_WORK_SIZE(CHANNELS)];
rc::PPMOut ppm_out(CHANNELS, ppm_input, ppm_work, CHANNELS);
int test = 0;

void setup() {
  Serial.begin( 115200 );
  Serial.println("Starting Joy2RC - Initiating JoyStick USBHOST");

  if (Usb.Init() == -1)
      Serial.println("OSC did not start.");
      
  delay( 200 );

  if (!Hid.SetReportParser(0, &Joy))
      Serial.println("oooohhhh shhiiiitttt");
  //    ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1);

	for (uint8_t i = 0;  i < CHANNELS; ++i)
	{	
		ppm_input[i] = 0;
	}
  rc::Timer1::init();
  //ppm_out.setPulseLength(13); //what does the 9x expect?
  //ppm_out.setPauseLength(300); //as above?
  ppm_out.start(8); //use pin 9 or 10
}

void loop() {
  Usb.Task();
  
  ppm_input[0] = map(JoyEvents.X, 0, 0xFF, 1000, 2000);
  ppm_input[1] = map(JoyEvents.Y, 0, 0xFF, 1000, 2000);
  ppm_input[2] = map(JoyEvents.Z, 0, 0xFF, 1000, 2000);
  ppm_input[3] = map(JoyEvents.Rz, 0, 0xFF, 1000, 2000);
  /*ppm_input[0] = map(0, 0, 100, 1000, 2000);
  ppm_input[1] = map(50, 0, 100, 1000, 2000);
  ppm_input[2] = map(100, 0, 100, 1000, 2000);
  ppm_input[3] = map(test, 0, 100, 1000, 2000);*/
  /*ppm_input[0] = map(50, 0, 100, 1000, 2000);
  ppm_input[1] = map(50, 0, 100, 1000, 2000);
  ppm_input[2] = map(50, 0, 100, 1000, 2000);
  ppm_input[3] = map(50, 0, 100, 1000, 2000);*/
  ppm_out.update();
  
  /*test += 50;
  
  if (test > 100)
    test = 0;
  
	for (uint8_t i = 0;  i < CHANNELS; ++i)
	{	
    Serial.print(i+1);
  Serial.print(": ");
  Serial.print(ppm_input[i]);
    Serial.print(" ");
	}
  Serial.println();
  
  delay(1000);*/
  /*if (JoyEvents.Z == 0xFF) {
    Serial.println(JoyEvents.X);
    Serial.println(ppm_input[0]);
  }*/
}
