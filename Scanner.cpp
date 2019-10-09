#include "Scanner.h"

//Constructor
Scanner::Scanner(string tempFileName) {
	this->fileName = tempFileName;
}




//This is the driver that runs the program
//After main, all other parts of the program are called from here. 
int Scanner::driver() {

	/*return 1;
	fileName = "tst.txt";
	cout << "File Name: " << fileName << endl;*/
	
	//declarations for Token and Automaton objects
	Token token;
	Automaton automaton = Automaton(token);

	//creates file object
	fstream myFile;

	

	//opens file
	myFile.open(fileName);

	if (myFile.is_open() == false) {
		cout << "File did not open correctly, check file name." << endl;
		return -1;
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
		token.next();
		while (token.kind() != "END") {

			cout << "Position: " << token.position() << endl;
			cout << "Kind: " << token.kind() << endl;
			cout << "Value: " << token.value() << endl;
			cout << endl << endl;
			token.next();

		}
	}


	myFile.close();
	return 0;
}
