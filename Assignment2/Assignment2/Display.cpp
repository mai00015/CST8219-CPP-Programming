/*******************************************************************************
Filename:			Display.cpp
Version:			1.0
Author:				Kha Mai
Student No:			040780292
Course Name/Number:	C++ Programming CST8219
Lab Sect:			303
Assignment #:		2
Assignment name:	Animation Project in C++ using Container Classes
and Overloaded Operators
Due Date:			December 09 2017
Submission Date:	December 09 2017
Professor:			Andrew Tyler
Purpose:			Practice by using C++ to code (Develop from assignment1 ). This file is used
					to initialize and copy constructor, destroy and output
********************************************************************************/
#include <iostream>
#include <string>
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
Function name:			Display (parameter constructor)
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
Function name:			Display (destructor)
Purpose:				To destroy char pointer name
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Display::~Display() {
	delete[]name;
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
	/* Output fields of Display class */
	os << "\tname = " << display.name << "; pixel_x = " << display.pixel_x
		<< "; pixel_y = " << display.pixel_y << "; duration = " << display.duration << endl;
	os << "\tCounting the seconds for this Display: ";
	for (int i = 1; i <= display.duration; i++)
		os << i << ", ";
	return os;
}