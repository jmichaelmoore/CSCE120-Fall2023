#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

int main() {
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "frozen.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams
	ifstream censorWdsIn = ifstream(censorWordsFilename);
	ifstream originalIn(originalTextFilename);
	ofstream censorOut{censoredTextFilename};

	// make sure all files were opened and give feedback if not
	if (!censorWdsIn.is_open()) {
		cerr << "Unable to open file " << censorWordsFilename << endl;
		return 1;
	}
	if (!originalIn.is_open()) {
		cerr << "Unable to open file " << originalTextFilename << endl;
		return 1;
	}
	if (!censorOut.is_open()) {
		cerr << "Unable to open file " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	string censorWds;
	string wd;
	while (censorWdsIn >> wd) {
		censorWds = censorWds + wd + " ";
	}

	// print out list of censored words (for debugging) remove later from final program
	cout << "censorWds: " << censorWds << endl;

	// read original, process and send to output
	// process line by line
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line
	while (!originalIn.eof()) {
		string line;
		getline(originalIn, line);
		istringstream issCensor(censorWds);
		string wd;
		while (issCensor >> wd) {
			unsigned int location = line.find(wd);
			if (location != string::npos) {
				// start here replace word
			}
		}
		censorOut << line << endl;
	}
}