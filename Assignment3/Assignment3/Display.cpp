/*******************************************************************************
Filename:			Display.cpp
Version:			1.0
Author:				Kha Mai
Student No:			040780292
Course Name/Number:	C++ Programming CST8219
Lab Sect:			303
Assignment #:		3
Assignment name:	Animation Project in C++ using Polymorphic Inheritance and RTTI
Due Date:			January 06 2018
Submission Date:	January 04 2018
Professor:			Andrew Tyler
Purpose:			Practice by using C++ to code (Develop from assignment 2 ). This file is used
to initialize and copy constructor, destroy and output
********************************************************************************/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#include "Display.h"

/*******************************************************************************
Function name:			Display (parameter constructor)
Purpose:				To initialize values in parameter to fields
In parameters:			int, int, int, char*
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Display::Display(int x, int y, int duration, char* name) {

	/* Assign values to fields */
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, (strlen(name) + 1), name);
}

/*******************************************************************************
Function name:			Display (copy constructor)
Purpose:				To copy values from parameter to fields
In parameters:			const Display&
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Display::Display(const Display& display) {
	/* Copy values to fields */
	this->pixel_x = display.pixel_x;
	this->pixel_y = display.pixel_y;
	this->duration = display.duration;
	this->name = new char[strlen(display.name) + 1];
	strcpy_s(this->name, (strlen(display.name) + 1), display.name);
}

/*******************************************************************************
Function name:			operator<<
Purpose:				To set the output for every fields in display by using
						overloading operator
In parameters:			ostream&, Display&
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
ostream& operator<<(ostream& os, Display& display) {
	/* Define local variable */
	int counter = 0;
	/* Is used for time */
	time_t startsec, oldsec, newsec;
	/* Set to null at the beginning */
	startsec = oldsec = time(NULL);
	/* Is used to loop the time */
	int duration = display.duration;

	/* Output fields of Display class */
	os << "\tDisplay name = " << display.name << "; pixel_x = " << display.pixel_x
		<< "; pixel_y = " << display.pixel_y << "; duration = " << display.duration << endl;
	os << "\tCounting the seconds for this Display: ";

	while (duration) {
		/* Set the time for newsec */
		newsec = time(NULL);
		/* If newsec is greater than oldsec, run this one */
		if (newsec > oldsec) {
			cout << newsec - startsec << ", ";
			/* Make oldsec equal to newsec */
			oldsec = newsec;
			duration--;
		}
	}
	os << "\n\tMemory requirements = " << display.BufferSize() << " bytes\n";
	return os;
}