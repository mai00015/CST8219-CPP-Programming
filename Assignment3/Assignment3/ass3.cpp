// ass3.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
#include "Frame.h"
#include "Animation.h"

bool running = true;

int main(void)
{
	char selection;
	bool running = true;
	Animation A("A");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // in main, after local declarations

	while (running)
	{
		cout << "MENU\n 1. Insert a Frame\n 2. Delete all the Frames\n 3. Run the Animation\n 4. Quit\n" << endl;
		fflush(stdin);
		cin >> selection;

		switch (selection)
		{
		case '1':
			A.InsertFrame();
			break;
		case '2':
			A.DeleteFrames();
			break;
		case '3':
			cout << A << endl;
			break;
		case '4':
			running = false;
			break;
		default:
			break;
		}
	}

	return 0;
}