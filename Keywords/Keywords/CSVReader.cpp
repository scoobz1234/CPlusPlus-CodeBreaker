/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#include "CSVReader.h"

CSVReader::CSVReader() {}
CSVReader::~CSVReader() {}

std::vector<std::string> CSVReader::GetData(std::vector<std::string> &gWords, std::vector<std::string> &gHints)
{
	// here is where we take the integer value num_words and set it to the constant value of the file size
	NUM_WORDS = CheckFileSize("list.txt");

	//now we read the file, and write to our std::vectors...
	ReadFromFile("list.txt", gWords, gHints, NUM_WORDS);

	//return our two std::vectors back to main...
	return gWords, gHints;
}

std::vector<std::string> CSVReader::ReadFromFile(const char* fileName, std::vector<std::string> &gWords, std::vector<std::string> &gHints, const int fileSize)
{
	//this is a class instantiation of the fstream class, i is for input
	std::ifstream inFile;
	//Open the file
	inFile.open(fileName);

	//Make sure we could open the file...
	if (inFile.fail())
	{
		std::cerr << "There was a problem opening the file: " << fileName << std::endl;
		exit(1);
	}

	//Temp variables to hold data from CSV file...
	std::string word;
	std::string hint;

	//while we havent reached the end of the file... which is what inFile.good() function does..
	while (inFile.good())
	{
		//we go line by line, set the first word of the line to word, it stops when it reaches a comma...
		getline(inFile, word, ',');
		//then the second set of words gets written to hint, and stops when it reaches a carriage return...
		getline(inFile, hint, '\n');
		//then we take the std::string word, and hint and populate our std::vectors with them...
		gWords.push_back(word);
		gHints.push_back(hint);
	}

	//Memory Management, close the file...
	inFile.close();

	//return the std::vectors to the GetData function...
	return gWords, gHints;
}

const int CSVReader::CheckFileSize(const char* fileName)
{
	//this is a class instantiation of the fstream class, i is for input
	std::ifstream inFile;
	//Open the file
	inFile.open(fileName);

	//Make sure we could open the file...
	if (inFile.fail())
	{
		std::cerr << "There was a problem opening the file: " << fileName << std::endl;
		exit(1);
	}

	//Find out how big our file is...
	std::string word; // used to check the first "std::string" in a line
	std::string hint; // used to check the second "std::string" in a line
	int count = 0; //so we can keep track of how many lines we have iterated through
	//while were not at the end of the file...
	while (!inFile.eof())
	{
		//were looking at the inFile and checking words and hints on each line...
		inFile >> word >> hint;
		//increase the counter as long as we havent hit the end of the file...
		count++;
	}

	//set a constant int to the count, so we can return a constant...
	const int numberOfWords = count;
	// Memory management, Close the file...
	inFile.close();
	//return the constant int...
	return numberOfWords;
}