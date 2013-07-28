=======
JoyToRC
=======

Simple sketch to convert the USB Gamepad/Joystick inputs to PPM signals for a
RC Transmitter such as the Turnigy 9X, or if you're **hardcore** you could even tie it
directly into a FrSky DIY kit.

Requirements
------------

* Arduino
* `Arduino USB Host Shield`_
* USB_Host_Sheild_ library
* ArduinoRCLib_
* Trainer cable (generally a typical mono audio jack) with pins on the other end for plugging into the shield.

.. _`Arduino USB Host Shield`: http://dx.com/p/usb-host-shield-expansion-board-google-android-compatible-for-arduino-blue-156155?tc=AUD&utm_source=GoogleshoppingAU&utm_medium=CPC&utm_content=156155&utm_campaign=436&gclid=CLTcvO7T0bgCFcZapgodghEAUw
.. _USB_Host_Sheild: https://github.com/felis/USB_Host_Shield_2.0
.. _ArduinoRCLib: http://sourceforge.net/projects/arduinorclib/

Todo
----

* Make the flippin' thing work! At the moment there is massive delays in changing the PPM values, and I have no idea why.
* Add support for Joystick.
