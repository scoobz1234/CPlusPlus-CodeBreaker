/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#include "InterceptMessage.h"

InterceptMessage::InterceptMessage() {}
InterceptMessage::~InterceptMessage() {}

void InterceptMessage::InterceptMessageScroll()
{
	//create the handle for the console...
	HANDLE hConsole;
	//set the handle to our instance of the console
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//set the console text color to windows code 2 which is green.
	SetConsoleTextAttribute(hConsole, 2);

	//Declaration of array for each row of characters. each row will have 80 characters...
	const int ROW_CHARACTER_COUNT = 80;
	char rowArray[ROW_CHARACTER_COUNT];
	//because of scope, and so these retain their values...we define these here...
	int j = 7; // used to start std::string streaks
	int k = 2; // used to end std::string streaks
	int l = 5; // used to start std::string streaks
	int m = 1; // used to end std::string streaks
	//loop to output rows of characters...
	int i = 0;

	//this loop is just so we can print x amount of lines before we stop the "message"
	for (int loopCount = 0; loopCount < 200; loopCount++) {
		// Output a random row of characters each row has 80 characters in it...
		// this loop will work until i = 80, then break out...
		for (i = 0; i < ROW_CHARACTER_COUNT; ++i)
		{
			//check to make sure were not writing over spaces..
			if (rowArray[i] != ' ')
			{
				//set current index in rowArray to a random character
				//were getting characters of ASCII values from '!' to '>'
				//j + the square of the index is our generator value...
				// 33 is the decimal value for ! 
				rowArray[i] = GetChar(j + (i * i), 33, 30);
				//if the square of the index + k modulo 71 = 0 then set the character
				//value color to white
				if (((i*i + k) % 71) == 0)
				{
					//takes a handle and sets its text to 7 which is windows code for light gray...
					SetConsoleTextAttribute(hConsole, 7);
				}
				else
				{
					//if its not zero, then take the text and set it to the windows code for green...
					SetConsoleTextAttribute(hConsole, 2);
				}
			}
			//output the array index to the console...
			std::cout << rowArray[i];
			//in case we set the color to light gray, reset it to green...
			SetConsoleTextAttribute(hConsole, 2);
		}

		j = (j + 31); //31 just works well, if we use a different number it seems to repeat itself alot...
		k = (k + 17); //same with these, the numbers just set up the best outcome and "patterns"
		l = (l + 47);
		m = (m + 67);
		rowArray[j % 80] = '-'; //modulus keeps the value between 0 and 79
		rowArray[k % 80] = ' '; //the - is the beginning of a character streak
		rowArray[l % 80] = '-'; //and spaces end the character streaks
		rowArray[m % 80] = ' '; //the value of j,k,l,m will be really large after awhile, so this keeps them low
		//set our index back to zero, so we can do the forloop over again...
		i = 0;
		// Delay to slowdown the output. i like 8...
		Sleep(8);
	}
	//give the user a little bit of time to see the text effect (code to break)
	Sleep(1000);
	//Clear the screen so we can start the guessing...
	system("cls");
	//finally set the color of the text back to white...
	SetConsoleTextAttribute(hConsole, 15);
}



