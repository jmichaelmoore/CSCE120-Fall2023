#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

string tolower(string wd) {
	for (unsigned int i=0; i<wd.length(); ++i) {
		wd.at(i) = tolower(wd.at(i));
	}	
	return wd;
}

string getReplace(string wd) {
	string retWd;
	for (unsigned int i=0; i<wd.length(); ++i) {
		char replacement = random()%5;
		switch (replacement) {
			case 0:
				retWd += '$';
				break;
			case 1:
				retWd += '*';
				break;
			case 2: 
				retWd += '%';
				break;
			case 3:
				retWd += '@';
				break;
			case 4: 
				retWd += '!';
				break;
		}
	}
	return retWd;
}

int main() {
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "frozen.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams
	ifstream censorWdsIn(censorWordsFilename);
	ifstream originalIn{originalTextFilename};
	ofstream censorOut = ofstream(censoredTextFilename);

	// make sure all files were opened and give feedback if not
	if (!censorWdsIn.is_open()) {
		cerr << "Unable to open file: " << censorWordsFilename << endl;
		return 1;
	}
	if (!originalIn.is_open()) {
		cerr << "Unable to open file: " << originalTextFilename << endl;
		return 1;
	}
	if (!censorOut.is_open()) {
		cerr << "Unable to open file: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	string censorWds;
	string censorWd;
	while(censorWdsIn >> censorWd) {
		censorWds = tolower(censorWds) + censorWd + " ";
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
		string linelower = tolower(line);
		istringstream cwds(censorWds);
		string wd;
		//cout << "npos: " << string::npos << endl;
		while (cwds >> wd) {
			cout << "wd: " << wd << endl;
			size_t location = 0;
			size_t startlocation = 0;
			do {
				location = linelower.find(wd, startlocation);
				cout << "location: " << location << endl;
				//start here!!!!
				if (location != string::npos) {
					line.replace(location, wd.size(), getReplace(wd));
					startlocation = location + wd.length();
				}
			} while (location != string::npos);
		}
		censorOut << line;
	}
}