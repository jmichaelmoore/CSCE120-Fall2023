#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

int main() {
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "original.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams

	// make sure all files were opened and give feedback if not

	// get list of words to censor from file

	// print out list of censored words (for debugging) remove later from final program

	// read original, process and send to output
	// process line by line
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line
}