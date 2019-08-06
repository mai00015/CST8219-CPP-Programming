/*******************************************************************************
Filename:			Animation.cpp
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
Purpose:			Practice by using C++ to code (Develop from assignment2 ). This file is used
					to create value and vector, then add into forward_list whenever user inputs.
					Also, calling object that inherited from Display
********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Animation.h"
#include "Frame.h"
#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"

/*******************************************************************************
Function name:			InsertFrame
Purpose:				To let user inputs, then add into forward_list that
stores name and vector
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::InsertFrame() {

	/* Define variable */
	/* Make a vector to store in forward_list */
	vector<Display*> vectorDisplay;
	/* To store name of frame */
	string fName, shader;
	/* Element inside vector */
	int pi_x, pi_y, duration, type = 0;
	/* How many display that can be input */
	int number = -1;
	/* Get the size of forward_list */
	int currentSize;
	/* To enter the position to input */
	int position = -1;
	/* Count to run the loop */
	int i = 0, j = 0;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> fName;

	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	/* To prevent user input negative number */
	do {
		cout << "Please enter the number of Displays: ";
		cin >> number;
	} while (number < 0);
	/* Run the loop depending on the number of display */
	for (i; i < number; i++) {
		/* Define char string to assign the display name */
		char dName[50];

		cout << "Please enter pixel x-width for Display #" << i << " pixel_x:";
		cin >> pi_x;
		cout << "Please enter pixel y-width for Display #" << i << " pixel_y:";
		cin >> pi_y;
		cout << "Please enter the duration for this Display: ";
		cin >> duration;
		cout << "Please enter the name for this Display: ";
		cin >> dName;
		do {
			cout << "Please enter the type for this display (1 = SystemMemoryDisplay, 2 = GPUMemoryDisplay): ";
			cin >> type;
		} while (type != 1 && type != 2);

		/* If type is 1, means that it is a SystemMemoryDisplay, push to vector */
		if (type == 1) {
			vectorDisplay.push_back(new SystemMemoryDisplay(pi_x, pi_y, duration, dName)); // CALL EACH CLASS
		}
		/* If type is 2, means that it is a GPUMemoryDisplay, push to vector */
		else {
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> shader;
			vectorDisplay.push_back(new GPUMemoryDisplay(pi_x, pi_y, duration, dName, shader)); // CALL EACH CLASS
		}
		cout << '\n';
	}

	/* Create new frame object to store frame name and vector */
	Frame tempFrame(fName, vectorDisplay);
	/* If forward_list is empty, run this one */
	if (this->frames.empty()) {
		cout << "This is the first Frame in the list\n" << endl;
		/* Add to the head */
		this->frames.push_front(tempFrame);
	}
	else {
		/* Calculate the current size of forward_list */
		currentSize = distance(this->frames.begin(), this->frames.end());
		/* If it has 1 frame inside, run this one */
		if (currentSize == 1) {
			/* Add after the head */
			this->frames.insert_after(this->frames.begin(), tempFrame);
			cout << "\n";
			return;
		}
		cout << "There are " << currentSize << " Frame(s) in the list" << endl;
		while (position < 0 || position >= currentSize) {
			cout << "Please specify the position, between 0 and " << currentSize - 1 << " to insert after : ";
			cin >> position;
		}
		/* Create an iterator to be assigned the head */
		auto iterator = this->frames.begin();
		/* This loop is used to move the iterator to the position that will be added */
		for (j; j < position; j++)
			iterator++;
		/* Add to the position */
		this->frames.insert_after(iterator, tempFrame);
		cout << "\n";
	}
}

/*******************************************************************************
Function name:			DeleteFrames
Purpose:				To delete all the frames in forward_list
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::DeleteFrames() {

	/* Destroy the forward_list */
	this->frames.clear();
	cout << "Clear frames in the animation\n" << endl;
}

/*******************************************************************************
Function name:			operator<<
Purpose:				To output Animation by calling frames and display
In parameters:			ostream&, Animation&
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
ostream & operator<<(ostream & os, Animation & animation) {
	int i = 0;

	if (animation.frames.empty())
		os << "No frames in the animation\n";
	else {
		auto iterator = animation.frames.begin();
		/* Ouput the Animation */
		os << "Animation " << animation.name << "\n"
			<< "Run the Animation" << endl;
		for (iterator; iterator != animation.frames.end(); iterator++) {
			os << "Frame #" << i++ << ":";
			os << *iterator << endl;
		}
		os << "Output finished" << endl;
	}
	return os;
}
