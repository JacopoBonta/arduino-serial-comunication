arduino_serial_comunication
===========================

A library that allows you to communicate with your Arduino via USB.

RELEASE NOTE:

#######LAST_VERSION_INFO#######
{arduinoserialcom.h _V: 1.0.0}

Date: 07/10/2014
Name: arduinoserialcom
Tipe of file: header
Version: 1
Revision: 0
Release: 0

#######PREVIOUS_VERSION#######
{N/D}
Date: N/D

#######FILE_DESCRIPTION#######

This header file contains the class Ascom wich allows you
	to simply comunicate with your Arduino.

ATTENTION: The Arduino must be connected to COM6.

Ascom has these types of members:

-Methods:
     >>>Ascom.Ccontroll method:

		The Ascom::Ccontrol method, controls if the Arduino is connected to COM6.

	-Syntax:
		bool Ccontrol();

	-Return Value:
		type: bool;
		If the Arduino is connected the method returns 1, else returns 0;

     >>>Ascom.Write method:

		The Ascom::Write method allows you to send an string of characters to the Arduino.

	-Syntax:
		void Write(
		   char* buf;
		   
		   );
		
     >>>Ascom.Read method:

		The Ascom::Read method allows you to reacive an string of characters from the Arduino.

	-Syntax:
		void Read(
		   char* inbuf;
		   
		   );

Were also implemented two overloads of operators with which you can easily
recall the methods of reading (>>) and writing (<<).
Example:
	#DEFINE MAX 100
	.
	.
	.
	Ascm arduino;

	arduino<<"Hello"; //send the string "Hello" to Arduino

	char recive[MAX];

	arduino>>recive; //recive the string from Arduino and save it to the array recive.
	.
	.
	.
