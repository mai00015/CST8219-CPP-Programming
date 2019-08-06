/*******************************************************************************
Filename:			Frame.cpp
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
					to implement the overloaded operators (+) and (<<) output operators
********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Frame.h"
#include "Display.h"

/*******************************************************************************
Function name:			Frame operator+
Purpose:				To concatenate 2 frames together  
In parameters:			Frame&
Out parameters:			Frame
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Frame Frame::operator+(Frame& frame) {
	/* Make a new name variable to store 2 names */
	string newName;
	/* Make a new vector to store 2 vectors */
	vector<Display> newDisplay;
	/* To count the loop */
	int i = 0;
	int j = 0;
	/* Get the current size */
	int size1 = this->displays.size();
	int size2 = frame.displays.size();
	/* Concatenate  2 file names */
	newName = this->fileName + "_" + frame.fileName;

	for (i; i < size1; i++)
		/* Add values into new vector */
		newDisplay.push_back(this->displays[i]);
	for (j; j < size2; j++)
		/* Continue to add values into new vector */
		newDisplay.push_back(frame.displays[j]);

	/* Create a new frame */
	Frame newFrame(newName, newDisplay);
	return newFrame;
}

/*******************************************************************************
Function name:			ostream& operator<<
Purpose:				To output the frame and then call output display
In parameters:			ostream&, Frame&
Out parameters:			ostream&
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
ostream& operator<<(ostream& os, Frame& frame) {
	/* Is used to count the loop */
	int i = 0;
	/* Get a current size */
	int size = frame.displays.size();
	/* Ouput the frames and call display to output */
	os << "\tfileName = " << frame.fileName << endl;
	for (i; i < size; i++) {
		os << "\tDisplay #" << i << ":" << frame.displays[i] << endl;
	}
	return os;
}