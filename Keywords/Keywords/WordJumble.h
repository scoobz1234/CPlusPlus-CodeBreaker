/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <windows.h>

class WordJumble
{
public:
	WordJumble();
	~WordJumble();
	//public run function takes in reference to hints and words std::vectors, and the word count
	void Run(std::vector<std::string> &words, std::vector<std::string> &hints, const int NUM_WORDS);

private:
	//storage variables for selected words and hints
	std::string theWord;
	std::string theHint;

	//storage std::vector of std::std::strings for holding already guessed words...
	std::vector<std::string> previouslyUsedWords;

	//FUNCTIONS//
	std::string GetWord(std::vector<std::string> words, const int index); //returns std::std::string
	std::string GetHint(std::vector<std::string> hints, const int index); //returns std::std::string
	std::string JumbleWord(std::string word); //returns std::std::string
};

