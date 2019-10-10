#include "Scanner.h"

//Constructor
Scanner::Scanner(string tempFileName) {
	this->fileName = tempFileName;	
}




//This is the driver that runs the program
//After main, all other parts of the program are called from here. 
int Scanner::driver() {
	
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
	bool error = false;

	//This while statement reads a .txt file line by line
	while (getline(myFile, line)) {

		automaton.identifyChar(line, lineNumber, error);
		lineNumber++;
	}
	automaton.evaluateEndOfText();
	
	if (error == false) {
		next();
		while (token.kind() != "END") {

			cout << "Position: " << position() << endl;
			cout << "Kind: " << kind() << endl;
			cout << "Value: " << value() << endl;
			cout << endl << endl;
			token.next();

		}
	}


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
