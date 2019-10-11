#include "Scanner.h"

//Constructor
Scanner::Scanner(Token &tempToken, string tempFileName) {
	token = &tempToken;
	this->fileName = tempFileName;	
}


//This is the driver that runs the program
//After main, all other parts of the program are called from here. 
int Scanner::driver(bool &error) {
	
	//declarations for Token and Automaton objects
	
	Automaton automaton = Automaton(*token);

	//creates file object
	fstream myFile;

	//opens file
	myFile.open(fileName);

	if (myFile.is_open() == false) {
		cout << "File did not open correctly, check file name." << endl;
		exit(EXIT_FAILURE);
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

