/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class CSVReader
{

public:
	CSVReader();
	~CSVReader();

	//this is our public function called by main, this returns a std::string std::vector...
	//this function takes in two std::vectors of std::strings in as arguments, were taking
	//a reference to the std::vectors so we can change the actual value of the struct from main...
	std::vector<std::string> GetData(std::vector<std::string> &gWords, std::vector<std::string> &gHints);

private:
	//this function is the actual function that will read the file, and get words and hints
	//from the file. file size will be populated from the check file size function...
	std::vector<std::string> ReadFromFile(const char* fileName, std::vector<std::string> &words, std::vector<std::string> &hints, int fileSize);

	//this function will iterate through the file, and find out how long it is.
	const int CheckFileSize(const char* fileName);

	//number of words is the variable we will store our file length into...
	int NUM_WORDS;
};
