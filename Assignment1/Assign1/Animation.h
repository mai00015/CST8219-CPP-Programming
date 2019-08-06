/*******************************************************************************
Filename:			Frame.h
Version:			1.0
Author:				Andrew Tyler
Student No:			040780292
Course Name/Number:	C++ Programming CST8219
Lab Sect:			303
Assignment #:		1
Assignment name:	Animation Project in C++
Due Date:			October 14 2017
Submission Date:	October 6 2017
Professor:			Andrew Tyler
Purpose:			To define a class and function definition for Animation
********************************************************************************/
#pragma once
#include "Frame.h"
//#include <time.h>
//#include <iostream>
//using namespace std;

class Animation {
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void DeleteFrames();
	void RunFrames();
};
