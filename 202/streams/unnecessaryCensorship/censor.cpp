#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

string tolower(string wd) {
	for (size_t i=0; i<wd.size(); ++i) {
		wd.at(i) = tolower(wd.at(i));
	}
	return wd;
}

string getReplacement(string wd) {
	string replacement;
	for (size_t i=0; i<wd.size(); ++i) {
		int randVal = rand()%5;
		switch (randVal) {
			case 0:
				replacement += '#';
				break;
			case 1: 
				replacement += '$';
				break;
			case 2:
				replacement += '!';
				break;
			case 3:
				replacement += '@';
				break;
			case 4:
				replacement += '~';
				break;
		}
	}
	return replacement;
}

int main() {
	srand(time(NULL));
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
		censorWds = tolower(censorWds) + wd + " ";
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
		string linelower;
		linelower = tolower(line);
		istringstream issCensor(censorWds);
		string wd;
		//cout << "npos: " << string::npos << endl;
		size_t location = 0;
		size_t startlocation = 0;
		while (issCensor >> wd) {
			do {
				location = linelower.find(wd, startlocation);
				if (location != string::npos) {
					//linelower.replace(location, wd.size(), getReplacement(wd));
					line.replace(location, wd.size(), getReplacement(wd));
					startlocation = location + wd.size();
				}
			} while (location != string::npos);
		}
		censorOut << line << endl;
	}
}