/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#pragma once
#include <iostream>
#include <windows.h>

class InterceptMessage
{
public:
	InterceptMessage();
	~InterceptMessage();
	//public function for main to call...
	void InterceptMessageScroll();

private:

	/*
	takes in argument Generator, and returns a char
	from the range of Base + Range -1.
	because were using ascii if the base is lets say '9'
	note were using single quotes... so '9' on the ascii
	chart is 59.. this is an inline function as its so small...
	*/
	char GetChar(int generator, char base, int range)
	{
		return (base + (generator % range));
	}
};

