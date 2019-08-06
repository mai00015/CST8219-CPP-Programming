/*******************************************************************************
Filename:			Frame.cpp
Version:			1.0
Author:				Kha Mai
Student No:			040780292
Course Name/Number:	C++ Programming CST8219
Lab Sect:			303
Assignment #:		1
Assignment name:	Animation Project in C++
Due Date:			October 14 2017
Submission Date:	October 6 2017
Professor:			Andrew Tyler
Purpose:			Practice by using C++ to code (similar to assignment 0). This file is used
					to implement constructor and destructor by defining file name and next inside each frame.
					After that, delete file name
********************************************************************************/
#include"Frame.h"

/*******************************************************************************
Function name:			Frame (Constructor)
Purpose:				To initialize file name and next in each frame by setting it to null
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Frame::Frame() {
	fileName = nullptr;
	pNext = nullptr;
}

/*******************************************************************************
Function name:			~Frame (Destructor)
Purpose:				Used to delete file name and set it point to null
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Frame::~Frame() {
	delete fileName;
	fileName = nullptr;
}
