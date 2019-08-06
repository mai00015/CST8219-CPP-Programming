/*******************************************************************************
Filename:			Frame.cpp
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
					to copy value into constructor for each object's Inheritance and (<<) output operators
********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Frame.h"
#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"

/*******************************************************************************
Function name:			Frame (copy constructor)
Purpose:				To copy values from parameter to fields
In parameters:			const Frame&
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Frame::Frame(const Frame& frame) {
	/* Define local variable */
	int i;
	int size = frame.displays.size();
	/* Copy values to fields */
	this->fileName = frame.fileName;
	/* This loop is used to copy value into each object that is inheritance */
	for (i = 0; i < size; i++) {
		/* Using dynamic_cast to cast to a specific child */
		SystemMemoryDisplay* systemDisplay = dynamic_cast<SystemMemoryDisplay*>(frame.displays[i]);
		GPUMemoryDisplay* GPUDisplay = dynamic_cast<GPUMemoryDisplay*>(frame.displays[i]);

		if (systemDisplay)
			this->displays.push_back(new SystemMemoryDisplay(*systemDisplay));
		if (GPUDisplay)
			this->displays.push_back(new GPUMemoryDisplay(*GPUDisplay));
	}
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
	int i;
	int size = frame.displays.size();

	/* Ouput the frames and call display to output */
	os << "\tfileName = " << frame.fileName << endl;
	for (i = 0; i < size; i++) {

		/* Using dynamic_cast to cast to a identify a specific child */
		SystemMemoryDisplay* systemDisplay = dynamic_cast<SystemMemoryDisplay*>(frame.displays[i]);
		GPUMemoryDisplay* GPUDisplay = dynamic_cast<GPUMemoryDisplay*>(frame.displays[i]);

		os << "\tDisplay #" << i << ": ";
		if (systemDisplay) {
			os << "System Memory Display" << endl;
			os << *systemDisplay << endl;
		}
		if (GPUDisplay) {
			os << "GPU Memory Display. Shader = " << GPUDisplay->GetShader() << endl;
			os << *GPUDisplay << endl;
		}
	}
	return os;
}
