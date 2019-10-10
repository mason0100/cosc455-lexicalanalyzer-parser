#include "Scanner.h"

//Constructor
Scanner::Scanner(string tempFileName) {
	this->fileName = tempFileName;	
}




//This is the driver that runs the program
//After main, all other parts of the program are called from here. 
int Scanner::driver(bool &error) {
	
	//declarations for Token and Automaton objects
	
	Automaton automaton = Automaton(token);

	//creates file object
	fstream myFile;

	//opens file
	myFile.open(fileName);

	if (myFile.is_open() == false) {
		cout << "File did not open correctly, check file name." << endl;
		exit(0);
	}

	//string variable for reading file 
	string line;

	int lineNumber = 1;

	//This while statement reads a .txt file line by line
	while (getline(myFile, line)) {

		automaton.tokenizeFile(line, lineNumber, error);
		lineNumber++;
	}
	automaton.evaluateEndOfText();
	
	myFile.close();
	return 0;
}

void Scanner::next() {
	token.next();
}


string Scanner::kind() {
	return token.kind();
}


string Scanner::value() {
	return token.value();
}


string Scanner::position() {
	return token.position();
}
