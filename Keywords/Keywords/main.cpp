/*Copyright © 2019, Stephen R Ouellette*/
/*Word Jumble Program Title: Keywords*/
#include "CSVReader.h"
#include "InterceptMessage.h"
#include "WordJumble.h"

//defining a struct that holds the std::string std::vectors...
//the array will store all our words and hints for us...
struct ArrayData
{
	//std::vector of std::strings we store words...
	std::vector<std::string> words;
	//std::vector of std::strings we store our hints...
	std::vector<std::string> hints;
};

int main(int argc, char* argv[])
{
	//create an instance of our struct, call it data...
	ArrayData data;
	//create an instance of our file reader, call it filereader
	CSVReader fileReader;

	//call the file reader get data function, and populate our
	//structs std::vectors with the information in the file...
	fileReader.GetData(data.words, data.hints);

	std::cout << "\t\tWe have Intercepted a message from a foreign country\n\n" << std::endl;
	std::cout << "The message reads as follows: \n\n" << std::endl;

	system("pause");

	//create an instance of the intercept message class...
	InterceptMessage message;
	//call the message function intercept message scroll...
	//this will show the user some random matrix looking code...
	message.InterceptMessageScroll();

	//print some information to the user...
	std::cout << "\n\nInformation Collected from Intercepted Message...\n\n" << std::endl;
	//let the user know how many words they need to decipher...
	std::cout << "There are: " << data.words.size() << " words you must decipher..." << std::endl;

	//create the instance of the wordJumble object
	WordJumble wordJumble;
	//run the Run function from the instanced wordJumble object.
	//this takes in a reference to words,hints, and the size
	wordJumble.Run(data.words, data.hints, data.words.size());

	return 0;
}
