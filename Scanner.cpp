#include "Scanner.h"

void Scanner::driver() {

	Automaton automaton;

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
	automaton.printTokenList();
}


//reads the next lexeme in the input file
void Scanner::next() {

}


//returns the kind of the lexeme that was just read.
string Scanner::kind() {

}


//returns the value of the lexeme (if it is an “ID” or a “NUM”
string Scanner::value(){

}


//returns the position of the lexeme that was just read
int Scanner::position() {

}