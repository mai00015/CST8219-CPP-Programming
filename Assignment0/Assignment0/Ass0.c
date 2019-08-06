/*******************************************************************************
Filename:			ass0.c
Version:			1.0
Author:				Kha Mai
Student No:			040780292
Course Name/Number:	C++ Programming CST8219
Lab Sect:			303
Assignment #:		0
Assignment name:	Animation Project in C
Due Date:			September 24 2017
Submission Date:	September 21 2017
Professor:			Andrew Tyler
Purpose:			Review for C language. Using linked list to add data in different position
					from keyboard. Then, it should display exactly the same order. After that,
					when it is deleted, it should free every nodes inside that linked list.
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct Frame {
	char* fileName;
	struct Frame* pNext;
};

struct Animation {
	struct Frame* frames;
};

// Forward declarations
void initAnimation(struct Animation*);
void insertFrame(struct Animation*);
void deleteFrames(struct Animation*);
void runFrames(struct Animation*);

/*******************************************************************************
Function name:			main
Purpose:				main function to start by showing the menu to the user 
In parameters:			none
Out parameters:			0 if it is success
Version:				1.0
Author:					Andrew Tyler
*******************************************************************************/

int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	struct Animation A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	initAnimation(&A);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame\n 2. Delete all the Frames\n 3. Run the Animation\n 4. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':insertFrame(&A); break;
		case '2':deleteFrames(&A); break;
		case '3':runFrames(&A); break;
		case '4':RUNNING = FALSE; deleteFrames(&A); break;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
		while ((response = getchar()) != '\n' && response != EOF);// clear input buffer
	}
	return 0;
}

/*******************************************************************************
Function name:			runFrames
Purpose:				Run the Animation to show the list of Frames in detail
						one after another at 1 second intervals
In parameters:			struct Animation* pA
Out parameters:			none
Version:				1.0
Author:					Andrew Tyler
*******************************************************************************/

void runFrames(struct Animation* pA)
{
	int counter = 0;
	time_t startsec, oldsec, newsec;
	struct Frame* iterator = pA->frames;

	if (pA->frames == 0)
	{
		printf("No frames in the animation\n");
		return;
	}

	printf("Run the Animation\n");
	startsec = oldsec = time(NULL);
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("Frame #%d, time = %d sec\n", counter++, newsec - startsec);
			printf("Image file name = %s\n", iterator->fileName);
			iterator = iterator->pNext;
			oldsec = newsec;
		}
	}
}

/*******************************************************************************
Function name:			initAnimation
Purpose:				To initialize the Animation by setting it to NULL
In parameters:			struct Animation* pA
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/

void initAnimation(struct Animation* pA)
{
	pA->frames = NULL; // initialize the Animation to null
	return;
}

/*******************************************************************************
Function name:			insertFrame
Purpose:				To insert data into exactly positions that input from keyboard
						by using pointer and linked list
In parameters:			struct Animation* pA
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/

void insertFrame(struct Animation* pA) {

	struct Frame* head = pA->frames; // set head equal to frame in the Animation
	struct Frame* iterator; // used to get a new data
	iterator = (struct Frame*)malloc(sizeof(struct Frame));

	char letter[50];
	char *str;
	int position;
	int counter = 0;
	int i = 1;

	printf("Insert a Frame in the Animation \n");
	printf("Please enter the Frame filename: ");

	scanf("%49s", letter); // scan a character
	str = (char *)malloc(strlen(letter) + 1); // memory allocation

	strcpy(str, letter); // copy from array to pointer string

	// initialize a new data
	iterator->fileName = str;
	iterator->pNext = 0;

	// check if the Animation is null or not
	if (!pA->frames) { 
		printf("This is the first Frame in the list\n");
		pA->frames = iterator; // insert to the Animation
		return;
	}

	// counter how many frames inside the Animation
	while (head) {
		counter++;
		head = head->pNext;
	}

	head = pA->frames; // set it to the beginning again
	printf("There are %d Frame(s) in the list. Please specify the position (<= %d) to insert at : ", counter, counter);
	scanf("%d", &position); // input from keyboard
	
	// insert into the middle and tail position
	if (position > 0) {
		for (i; head != NULL && i <= position; i++) {

			// add the new frame
			if (i == position) {
				iterator->pNext = head->pNext;
				head->pNext = iterator;
				break; // done, break the loop and return
			}
			else
				head = head->pNext; // not equal, go to the next position
		}
	}

	// insert into the head position
	if (position == 0) {
		iterator->pNext = head;
		pA->frames = iterator;
	}

	// position < 0 return
}

/*******************************************************************************
Function name:			deleteFrames
Purpose:				To delete every nodes (frames) inside the Animation and set it to NULL
In parameters:			struct Animation* pA
Out parameters:			none
Version:				1.0
Author:					Kha Mai
*******************************************************************************/

void deleteFrames(struct Animation* pA) {

	// check if it is not null, delete
	while (pA->frames) {

		struct Frame *temp = pA->frames; // temporary frame to delete
		pA->frames = pA->frames->pNext; // go to the next frame

		if (!pA->frames) // done, print this statement
			printf("Delete all the Frames from the Animation\n");

		free(temp->fileName); // delete data
		free(temp); // delete node
	}
}