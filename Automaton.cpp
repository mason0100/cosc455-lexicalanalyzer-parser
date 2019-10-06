#include "Automaton.h"


//Class constructor
Automaton::Automaton() {

}


//Deconstructor
Automaton::~Automaton() {
	cout << "Class is deleted" << endl;// for testing

}


//this is the function that identifies the tokens 
void Automaton::identifyChar(string line, int lineNumber) {

	//start and read will point to index numbers on the char[] array for the string line
	int start = 0;
	int read = 0; 
	//will skip if the line is blank
	if (line != "") {
		//processes until read == line.length 
		while(read < line.length()) {
			char c = line[read];
			switch (c) {
			case ' ':
				processWhiteSpace(line, start, read);
				//insert function to test for white space
				break;
			case '=':
				isEqualsSymbol(line, start, read);
				//insert function
				break;
			case '<':
				isLessThanSymbol(line, start, read);
				//insert function
				break;
			case '+':
				isPlusSymbol(line, start, read);
				//insert function
				break;
			case '-':
				isMinusSymbol(line, start, read);
				//insert function
				break;
			case '*':
				isMultiplicationSymbol(line, start, read);
				//insert function
				break;
			case '/':
				isDivisionSymbol(line, start, read);
				//insert function, must test for comment out and '/' keyword
				break;
			case '_':
				isUnderscoreSymbol(line, start, read);
				//insert function
				break;
			case 'f':
				isNot(line, start, read);
				//insert function to test for "false"
				break;
			case 't':
				isTrue(line, start, read);
				//insert function to test for "true"
				break;
			case 'n':
				isNot(line, start, read);
				//insert function to test for "not"
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			//case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			//case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			//case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				isIdentifier(line, start, read);
				//function for identifiie goes here
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				isNumber(line, start, read);
				//function for Integral Literal goes here
				break;
			
			default:
				//insert error fuction
				break;
			}
		}
	}
}//end identifyChar()



//Returns true is the token is '='
bool Automaton::isEqualsSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '=') {
		return true; 
	}
	return false;
}


//Returns true if token is '<'
bool Automaton::isLessThanSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '<') {
		return true;
	}
	return false;
}


//Returns true if token is '+'
bool Automaton::isPlusSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '+') {
		return true;
	}
	return false;
}


//Returns true if token is '-'
bool Automaton::isMinusSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '-') {
		return true;
	}
	return false;
}


//Returns true if token is '*'
bool Automaton::isMultiplicationSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '*') {
		return true;
	}
	return false;
}


//Returns true if token is '/'
bool Automaton::isDivisionSymbol(string line, int& start, int& read) {
	char token = line.at(read);
	if (token == '*') {
		return true;
	}
	return false;
}


//Returns true for the false keyword
//If the functions returns false, the read array pointer will be reset back to the start value
//Identifier will then be called to test is substring is an identfier token
bool Automaton::isFalse(string line, int& start, int& read) {
	if (line.at(read) == 'f') {
		read++;
		if (line.at(read) == 'a') {
			read++;
			if (line.at(read) == 'l') {
				read++;
				if (line.at(read) == 's') {
					read++;
					if (line.at(read) == 'e') {
						//does not increment read because this is the end of the token
						return true;
					}
				}	
			}	
		}	
	}
	//if the token is not 'false' read is reset and made equal to start for the isIdentfier() function
	read = start;
	return false;
}


//Returns true for keyword 'true'
//If the functions returns false, the read array pointer will be reset back to the start value
//Identifier will then be called to test is substring is an identfier token
bool Automaton::isTrue(string line, int& start, int& read) {
	if (line.at(read) == 't') {
		read++;
		if (line.at(read) == 'r') {
			read++;
			if (line.at(read) == 'u') {
				read++;
				if (line.at(read) == 'e') {
					return true;
				}
			}
		}
	}
	//if the token is not 'true' read is reset and made equal to start for the isIdentfier() function
	read = start;
	return false;
}


//Returns true is keyword is 'not'
//If the functions returns false, the read array pointer will be reset back to the start value
//Identifier will then be called to test is substring is an identfier token
bool Automaton::isNot(string line, int& start, int& read) {
	if (line.at(read) == 'n'){
		read++;
		if (line.at(read) == 'o') {
			read++;
			if (line.at(read) == 't') {
				return true;
			}
		}
	}
	//if the token is not 'not' read is reset and made equal to start for the isIdentfier() function
	read = start;
	return false;
}


//Returns true is a token is a number token
bool Automaton::isNumber(string line, int& start, int& read){
	char token = line.at(start);

	if (isDigit(token) == false) {
		return false;
	}

	int peak = read + 1;
	
	//set token to peak forward
	if (line.size()-1 > read) {
		token = line.at(peak);
		//read++;
	}

	while (true) {	
		//If token is a number increment read to match token 
		//or exit the loop
		if (isDigit(token)) {
			read++;
			peak++;
		}
		else {
			break;
		}
		//If line.size() > peak assign the peak char to token
		//or exit the loop
		if (line.size() > peak) {
			token = line.at(peak);
		}
		else {
			break;
		}
			
		
	}
	return true;
}


//Returns true if a token is an identifier
//Written to go into driver
bool Automaton::isIdentifier(string line, int& start, int& read) {

	char token = line.at(start);

	//if first character in token is not a letter return false
	//else continue with the function
	if (isLetter(token) ==  false){
		return false;
	}

	int peak = read + 1;

	//set token to peak forward
	if (line.size() - 1 > read) {
		token = line.at(peak);
		//read++;
	}

	while (true) {
		//If token is a number increment read to match token 
		//or exit the loop
		if (isLetter(token) || isDigit(token) || isUnderscore(token)) {
			read++;
			peak++;
		}
		else {
			break;
		}
		//If line.size() > peak assign the peak char to token
		//or exit the loop
		if (line.size() > peak) {
			token = line.at(peak);
		}
		else {
			break;
		}
	}
	//this funtion will return true after finding a char outside the identifier defintion
	//the start and read array pointers will be permanently changed and the next function will 
	//convert the substring between start and read

	return true;
}


//Returns true if the char at postion is '_'
//Written to go into the driver
bool Automaton::isUnderscoreSymbol(string line, int &start, int &read){
	char token = line.at(read);
	if (isUnderscore(token)) {
		return true;
	}
	
	//Returns true and sets start and read to tokenize the '_' char
	//in the next function

	return false;
}


//Returns true for the presence of the char '_'
//helpter method
bool Automaton::isUnderscore(char token) {
	if (token == '_') {
		return true;
	}
	return false; 
}


//Returns true if char is a letter in the language
//helper function
bool Automaton::isLetter(char token) {
	if (   token == 'a' || token == 'b' || token == 'c' || token == 'd' || token == 'e'
		|| token == 'f' || token == 'g' || token == 'h' || token == 'i' || token == 'j'
		|| token == 'k' || token == 'l' || token == 'm' || token == 'n' || token == 'o'
		|| token == 'p' || token == 'q' || token == 'u' || token == 'r' || token == 's'
		|| token == 't' || token == 'u' || token == 'v' || token == 'w' || token == 'x'
		|| token == 'y' || token == 'z'
		|| token == 'A' || token == 'B' || token == 'C' || token == 'D' || token == 'E'
		|| token == 'F' || token == 'G' || token == 'H' || token == 'I' || token == 'J'
		|| token == 'K' || token == 'L' || token == 'M' || token == 'N' || token == 'O'
		|| token == 'P' || token == 'Q' || token == 'U' || token == 'R' || token == 'S'
		|| token == 'T' || token == 'U' || token == 'V' || token == 'W' || token == 'X'
		|| token == 'Y' || token == 'Z') {

		return true;
	}
	//else
	return false;
}


//Returns true is char is a digit in the language
//helper function
bool Automaton::isDigit(char token) {
	if (token == '0' || token == '1' || token == '2' || token == '3' || token == '4'
		|| token == '5' || token == '6' || token == '7' || token == '8' || token == '9') {
		return true;
	}
	return false;
}

//Processes white spaces between tokens
void Automaton::processWhiteSpace(string line, int &start, int &read) {
	//peaks at the next char after read to see if it is a white space
	//if it is a white space read++
	//else start and read are updated to process the rest of the line
	while (line[read + 1] == ' ') {
		read++;
	}

	//set read and start to the begining of the next token to be processed
	read++;
	start = read;


	cout << line[read] << endl;//for testing DELETE LATER
}