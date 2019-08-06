// Frame.h
#pragma once
#include "Display.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Frame
{
	string fileName;
	vector<Display> displays;
public:
	Frame::Frame(string s, vector<Display> d) :fileName(s), displays(d) {}
	Frame operator+(Frame&);
	friend ostream& operator<<(ostream&, Frame&);
};
