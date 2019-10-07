#include "Scanner.h"

void Scanner::driver() {
	Token token;
	Automaton automaton = Automaton(token);

	//creates file object
	fstream myfile;

	//opens file
	myfile.open("test.txt");

	//string variable for reading file 
	string line;

	int lineNumber = 1;
	bool error = false;
	//This while statement reads a .txt file line by line
	while (getline(myfile, line)) {

		automaton.identifyChar(line, lineNumber, error);
		lineNumber++;

	}
	automaton.evaluateEndOfText();
	//token.printTokenList();

	token.next();
	while (token.kind() != "END") {
		
		cout << "Position: " << token.position() << endl;
		cout << "Kind: " << token.kind() << endl;
		cout << "Value: " << token.value() << endl;
		token.next();

	}
}
