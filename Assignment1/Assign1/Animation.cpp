/*******************************************************************************
Filename:			Animation.cpp
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
Purpose:			Practice by using C++ to code (similar to assignment 0). Using linked list 
					to add data in different position from keyboard. Then, it should display 
					exactly the same order. After that, when it is deleted, it should free every 
					nodes inside that linked list.
********************************************************************************/
#include "Animation.h"
#include "Frame.h"
#include <time.h>
#include <iostream>
using namespace std;
/*******************************************************************************
Function name:			Animation (Constructor)
Purpose:				To initialize new frames by setting it to null
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Animation::Animation() {

	frames = nullptr;
}

/*******************************************************************************
Function name:			~Animation (Destructor)
Purpose:				Used to call DeleteFrames function to delete every frames when the object ends
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
Animation::~Animation() {

	DeleteFrames();

}

/*******************************************************************************
Function name:			InsertFrame
Purpose:				To insert data into exactly positions that input from keyboard
						by using pointer and linked list
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::InsertFrame() {

	/* Define necessary variable */
	Frame *head = frames;
	Frame *iterator = new Frame;
	char *letter = new char[50];
	int count = 0;
	int position = -1;
	int i = 1;

	cout << "Insert a Frame in the Animation\n" << endl;
	cout << "Please enter the Frame filename: ";

	/* Read the input from keyboard */
	cin >> letter;
	/* Initialize a new data to iterator */
	iterator->GetfileName() = letter;

	/* If Frame is empty inside, add new character to head */
	if (!frames) {

		cout << "This is the first Frame in the list" << endl;
		/* Assign frames the value of iterator */
		frames = iterator;
		return;
	}
	/* Run the loop to count how many frame that was added inside Animation */
	while (head) {

		count++;
		/* Go to the next frame */
		head = head->GetpNext();
	}

	/* After run the loop, head is pointing to NULL. So assign it to the frames*/
	head = frames;
	/* This loop is to make sure the input is not outside the scope */
	while (position < 0 || position > count) {
		cout << "There are " << count << " Frame(s) in the list. Please specify the position (<= " << count << ") to insert at : ";
		cin >> position;
	}
	
	/* If the position is greater than 0, run this one to add new frame into middle and tail */
	if (position > 0) {
		/* This loop is used to move exactly to the position to be added */
		for (i; i <= position && head; i++) {

			/* If it is equal */
			if (i == position) {

				/* Add new frame */
				iterator->GetpNext() = head->GetpNext();
				head->GetpNext() = iterator;
				break;
			}
			/* Go to next location */
			head = head->GetpNext();
		}

	}
	/* Used to add the head */
	if (position == 0) {
		iterator->GetpNext() = head;
		frames = iterator;
	}
}

/*******************************************************************************
Function name:			DeleteFrames
Purpose:				To delete every nodes (frames) inside the Animation and set it to NULL
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::DeleteFrames() {

	/* Check if it is not null, delete */
	while (frames) {

		/* Temporary frame to delete */
		Frame *temp = frames;
		/* Go to next frame */
		frames = frames->GetpNext();
		/* If frame is null, run this one */
		if (!frames)
			cout << "Delete all the Frames from the Animation" << endl;
		/* Delete the frame */
		delete temp;

	}
}

/*******************************************************************************
Function name:			RunFrames
Purpose:				Run the Animation to show the list of Frames in detail
						one after another at 1 second intervals
In parameters:			none
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/
void Animation::RunFrames() {

	/* Define variables */
	int counter = 0;
	time_t startsec, oldsec, newsec;
	Frame* iterator = frames;

	/* If frame is null, run this one */
	if (!frames)
	{
		cout << "No frames in the animation" << endl;
		return;
	}

	cout << "Run the Animation" << endl;
	/*Set the time for startsec and oldsec */
	startsec = oldsec = time(NULL);

	/* Loop the iterator */
	while (iterator)
	{
		/* Set the time for newsec */
		newsec = time(NULL);
		/* If newsec is greater than oldsec, run this one */
		if (newsec > oldsec)
		{
			cout << "Frame #" << counter++ << " , time = " << newsec - startsec << " sec" << endl;
			cout << "Image file name = " << iterator->GetfileName() << endl;
			iterator = iterator->GetpNext();
			/* Make oldsec equal to newsec */
			oldsec = newsec;
		}
	}
}