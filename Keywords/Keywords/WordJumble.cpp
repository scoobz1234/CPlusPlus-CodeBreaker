/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#include "WordJumble.h"

WordJumble::WordJumble() {}
WordJumble::~WordJumble() {}

void WordJumble::Run(std::vector<std::string> &words, std::vector<std::string> &hints, const int NUM_WORDS)
{
	bool playAgain = false;

	do
	{
		//give the player 3 words to unscramble...
		for (int i = 0; i < 3; i++)
		{
			//call this only once!!!
			srand(static_cast<unsigned int>(time(0)));

			//get our random index
			int choice = (rand() % NUM_WORDS);

			//set the std::string using our getter function...
			theWord = GetWord(words, choice);
			//this will check if we have reached the end of our list of words...
			//if theWord comes back empty, we are done...
			if (theWord != " ")
			{
				//this will get the index of the current "theWord" variable..
				//this is so we have the correct hint that correlates to the word chosen...
				auto checkIndex = find(words.begin(), words.end(), theWord);
				//if the index == end basically means if the index is greater than the end of the std::vector...
				if (checkIndex == words.end())
				{
					//index not in std::vector
					theHint = GetHint(hints, choice);
				}
				//else number is in std::vector, and we can then get the correct hint...
				else
				{
					//this is so we can get the actual index and then pass it into the hint function...
					auto index = distance(words.begin(), checkIndex);
					//this will make sure the hint is correctly matched with the word...
					theHint = GetHint(hints, index);
				}
				//use the word we got above and jumble it using our jumble function...
				std::string jumble = JumbleWord(theWord);

				std::cout << "Unscramble the letters to make a word.\n" << std::endl;
				std::cout << "Enter 'hint' for a hint." << std::endl;
				std::cout << "Enter 'quit' to quit the game." << std::endl;
				std::cout << "Enter 'help' for futher assistance.\n\n" << std::endl;
				std::cout << "The scrambled code word is: " << jumble << std::endl;

				//storage variable for the users guess...
				std::string guess;
				std::cout << "\n\nYour guess: ";
				std::cin >> guess;

				//this is our check to make sure the user hasn't decided to quit
				//and to check if the users guess was incorrect.
				while ((guess != theWord) && (guess != "quit"))
				{
					//if the user types hint, print the hint...
					if (guess == "hint")
					{
						std::cout << theHint;
					}
					//if the user types help, perform these actions...
					else if (guess == "help")
					{
						//this will replace every other letter with a _ and print the other letters
						for (int i = 0; i < theWord.length(); i += 2)
						{
							//print the indexed letter...
							std::cout << theWord[i];
							//print every other letter as a _ to indicate a missing letter...
							if ((i + 1) < theWord.length())
							{
								std::cout << '_';
							}
						}
						std::cout << std::endl;
					}
					//nope not telling you about this command, but if you know it...
					else if (guess == "giveup")
					{
						//go ahead and print the word for the user...secret command :-)
						std::cout << "The word is: " << std::endl;
						std::cout << theWord << std::endl;
					}
					else
					{
						std::cout << "Sorry, that's not the word!";
					}
					//print the users guess...
					std::cout << "\n\nYour Guess: ";
					std::cin >> guess;
					std::cout << "\n\n";
				}
				//if the user types quit get out of the function
				if (guess == "quit")
				{
					playAgain = false;
					return;
				}
				std::cout << "You deciphered the word: " << guess << std::endl;
				std::cout << "\n\n";
				//give the user a few seconds to see they got it right...
				Sleep(1000);
				//clear the screen for the next word...
				system("cls");
			}
			//if we come back empty from GetWord, we are done, so lets exit out
			else
			{
				//return will get us back to the main function...
				return;
			}
		} //end of the for loop...
		std::cout << "Do you want to continue? (Y/N) ";

		char playerChoice;

		std::cin >> playerChoice;

		//Set players Choice to lower case...
		playerChoice = std::tolower(playerChoice);

		// this is shorthand of an if else statement...
		// ? is called a ternary operator because it requires three operands...
		// if playerchoice = y then it results in true, if not then it results false...
		playAgain = (playerChoice == 'y') ? true : false;

	} while (playAgain);
}

std::string WordJumble::GetWord(std::vector<std::string>words, const int index)
{
	//check if we havent guess all the words yet...
	if (previouslyUsedWords.size() < words.size())
	{
		std::cout << "You have guessed: " << previouslyUsedWords.size() << " words!" << std::endl;
		//check if the current indexed word is not already a guessed word...
		if (find(previouslyUsedWords.begin(), previouslyUsedWords.end(),
			words[index]) != previouslyUsedWords.end())
		{
			//new choice declaration and initialization...
			int newChoice = 0;
			//initialize and declare the boolean for our while loop...
			bool foundWord = true;
			//while loop that will keep requesting random numbers...
			//until we get a word that is not already a guessed word...
			while (foundWord)
			{
				//set new choice to a random number...
				newChoice = (rand() % words.size());

				//check again if the new word is a previously guessed word...
				if (find(previouslyUsedWords.begin(), previouslyUsedWords.end(),
					words[newChoice]) != previouslyUsedWords.end())
				{
					//if the word is already guessed then we set the bool to true...
					//if this bool is true we will run back through the loop...
					foundWord = true;
				}
				//if the word is not a guessed word, we set the bool to false...
				else
				{
					foundWord = false;
				}
			}
			//now that we have a word thats not in the guessed std::vector return it...
			previouslyUsedWords.push_back(words[newChoice]);
			return words[newChoice];
		}
		//the word is not in our guessed std::vector so return it...
		else
		{
			//add the word to our std::vector, so we won't use it again...
			previouslyUsedWords.push_back(words[index]);
			return words[index];
		}
	}
	else
	{
		std::cout << "You have guessed all of the words" << std::endl;
		return " ";
	}
}

//get hint function, takes an index and a std::vector of strings...
//returns the hint at index # x...
std::string WordJumble::GetHint(std::vector<std::string>hints, const int index)
{
	return hints[index];
}

//this is our jumbleword function, takes in a string as an argument
std::string WordJumble::JumbleWord(std::string word)
{
	std::string jumble = word;
	//get the length of the word...
	int length = jumble.size();
	//here is a little loop that will keep us from having a jumble
	//that isnt jumbled at all..
	while (jumble == word)
	{
		//loop through the word until you get to its end...
		for (int i = 0; i < length; ++i)
		{
			//set a random number between 0 and the length of the word...
			int index1 = (rand() % length);
			//set a second random number between 0 and the length of the word...
			int index2 = (rand() % length);
			//set a temp character with the character at word index 1...
			char temp = jumble[index1];
			//now take the character at index 1, and set it to the character
			//at index 2...
			jumble[index1] = jumble[index2];
			//then take the character at index 2, and set it equal to the
			//previous first character...
			jumble[index2] = temp;
		}
	}
	//return the jumbled word...
	return jumble;
}