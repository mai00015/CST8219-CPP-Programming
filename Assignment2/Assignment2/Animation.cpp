/*******************************************************************************
Filename:			Animation.cpp
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
					to create value and vector, then add into forward_list whenever user inputs.
					Besides, it is used to call overloading operator
********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Animation.h"
#include "Frame.h"
#include "Display.h"

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
	vector<Display> vectorDisplay;
	/* To store name of frame */
	string fName;
	/* Element inside vector */
	int pi_x, pi_y, duration;
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
		/* Define char pointer to assign the display name */
		char *dName = new char[50];

		cout << "Please enter pixel x for Display #" << i << " pixel_x:";
		cin >> pi_x;
		cout << "Please enter pixel y for Display #" << i << " pixel_y:";
		cin >> pi_y;
		cout << "Please enter the duration sec for this Display: ";
		cin >> duration;
		cout << "Please enter the name for this Display: ";
		cin >> dName;

		/* To store element into vector container */
		vectorDisplay.push_back(Display(pi_x, pi_y, duration, dName));
		delete dName;
	}
	/* Create new frame object to store frame name and vector */
	Frame tempFrame(fName, vectorDisplay);

	/* If forward_list is empty, run this one */
	if (this->frames.empty() == 1) {
		cout << "This is the first Frame in the list\n" << endl;
		/* Add to the head */
		this->frames.push_front(tempFrame);
		return;
	}
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
	while (position < 0 || position > currentSize) {
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

/*******************************************************************************
Function name:			DeleteFrames
Purpose:				To delete all the frames in forward_list
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::DeleteFrames() {
	this->frames.clear();
}

/*******************************************************************************
Function name:			operator[]
Purpose:				To return the location of the frames in forward_list
In parameters:			unsigned int
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Frame& Animation::operator[](unsigned int position) {
	/* Define variable to count the loop */
	unsigned int i = 0;
	/* Create an iterator to be assigned the head */
	auto iterator = frames.begin();
	for (i; i < position; i++)
		iterator++;
	/* Return pointer */
	return *iterator;
}

/*******************************************************************************
Function name:			operator+=
Purpose:				Is used to call operator+ function in frames and
						add new frame in forward_list
In parameters:			Frame&
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::operator+=(Frame& frame) {
	/* Add a new frame to forward_list */
	this->frames.push_front(frame);
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
	/* Get the current size of forward_list */
	int size = distance(animation.frames.begin(), animation.frames.end());
	/* Ouput the Animation */
	os << "Animation " << animation.name << "\n"
		<< "Run the Animation" << endl;
	for (i; i < size; i++) {
		os << "Frame #" << i << ":" << endl;
		os << animation[i];
	}
	os << "\nOutput finished" << endl;
	return os;
}
