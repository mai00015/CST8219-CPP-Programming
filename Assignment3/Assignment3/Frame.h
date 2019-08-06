// Frame.h
#pragma once
#include "Display.h"

class Frame
{
	string fileName;
	vector<Display*> displays;
public:
	Frame(string s, vector<Display*> d) :fileName(s), displays(d) {}
	Frame(const Frame&);
	~Frame()
	{
		vector<Display*>::iterator it;
		for (it = displays.begin(); it != displays.end(); it++)
			delete *it;
	}
	friend ostream& operator<<(ostream&, Frame&);
};