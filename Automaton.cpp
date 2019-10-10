#include "Automaton.h"


//Class constructor
Automaton::Automaton() {

}


//Class Construnctor
Automaton::Automaton(Token &temp) {
	lexem = &temp;
}


//Deconstructor
Automaton::~Automaton() {
	//Nothing in here for now.  

}


//this is the function that identifies the tokens 
void Automaton::identifyChar(string line, int lineNumber, bool &error) {

	//Inititate the test boolean for token eveluation
	bool test;

	//start and read will point to index numbers on the char[] array for the string line
	int start = 0;
	int read = 0; 

	//boolean for comment, if commentBool == true, exit line because the rest of the line is commented out
	bool commentBool = false;

	//will skip if the line is blank
	if (line != "") {

		//processes until read == line.length 
		while(read < line.length() && error == false && commentBool == false) {
			char c = line[read];
			switch (c) {
			case '\t':
			case ' ':
				processWhiteSpaceOrTab(line, start, read);
				break;
			case '=':
			case '<':
			case '+':
			case '-':
			case '*':
			case '_':
				test = isSingleCharKeyword(line, start, read);
				evaluateKeyword(test, line, lineNumber, start, read, error);
				break;
			case '/':
				test = isCommentSymbol(line, start, read);
				if (test == true) {
					//exit line because the rest of the line is commented out
					commentBool = true; 
				}
				else {// test == false
					test = isSingleCharKeyword(line, start, read);
					evaluateKeyword(test, line, lineNumber, start, read, error);
				}
				break;
			case 'o':// 'or'
			case 'a':// 'and'
			case 'f':// 'false
			case 't':// 'true
			case 'n':// 'not
				test = isSingleMuliCharKeyword(line, start, read);
				if (test == true) {
					evaluateKeyword(test, line, lineNumber, start, read, error);
				}
				else {// test == false
					test = isIdentifier(line, start, read);
					evaluateIdentifier(test, line, lineNumber, start, read, error);
				}
				break;
			//case 'a':
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
			//case 'o':
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
				test = isIdentifier(line, start, read);
				evaluateIdentifier(test, line, lineNumber, start, read, error);
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
				test = isNumber(line, start, read);
				evaluateNum(test, line, lineNumber, start, read, error);
				break;
			
			default:
				error = true;
				cout << "Error on line " << lineNumber << " at position " << start << endl;
				break;
			}
		}
	}
}//end identifyChar()


//print token list
//For testing purposes only
void Automaton::printTokenList() {
	lexem->printTokenList();
}


//This method will be called in the scanner function driver
//when the text document has been read
void Automaton::evaluateEndOfText() {
	lexem->addEndOFDocToken();
}


//Returns true if token is '//'
bool Automaton::isCommentSymbol(string line, int& start, int& read) {
	char token = line.at(start);
	int peak = read + 1;

	if (isForwardSlash(token) == true) {
		//checks is line.size() is large enough to have a comment keyword
		if (line.size() > peak) {
			token = line.at(peak);
			if (isForwardSlash(token) == true) {
				read++;
				return true;
			}
		}
	}
	//set read to equal start for isDivisionSymbol() function to evaluate
	read = start;
	return false;
}


//Single char Keyword test
bool Automaton::isSingleCharKeyword(string line, int& start, int& read) {
	char token = line.at(start);

	if (token == '=' || token == '<' || token == '+' || token == '-' || token == '*' || token == '/' || token == '_') {
		return true;
	}
	return false;
}


//Tests for char keywords with size greater than 1
bool Automaton::isSingleMuliCharKeyword(string line, int& start, int& read) {
	int lengthToRead = read - start + 1;
	char token = line.at(start);
	string keyword = "";
	keyword += token;

	int peak = read+1;

	while (true) {

		if (keyword.compare( "or") == 0 || keyword.compare("and") == 0 
			|| keyword.compare("not") == 0 ||  keyword.compare("true") == 0 
			|| keyword.compare("false") == 0) {
			
			return true;
		}
		else {
			read++;
			peak++;
		}
		if (line.size() >= peak) {
			token = line.at(read);
			keyword += token;
		}
		else {
			break;
		}
	}
	read = start;//reset read for isIdentifier()
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


//returns true if the char is a forward slash
bool Automaton::isForwardSlash(char token) {
	if (token == '/') {
		return true;
	}
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
void Automaton::processWhiteSpaceOrTab(string line, int &start, int &read) {
	//set read and start to the begining of the next token to be processed
	read++;
	start = read;
}


//Function decides whether to tokenize Indentifier or mark error and exit program
void Automaton::evaluateIdentifier(bool test, string line, int lineNumber, int& start, int& read, bool &error) {

	if (test == true) {
		//add to token list
		int lengthToRead = read - start + 1;
		string subStr = line.substr(start, lengthToRead);
		lexem->addIdentifierToken(subStr, lineNumber, start);

		//increment read to the next char to be read in the next driver loop
		read++;

		//set start to catch up to read so the next lexem can be taken 
		start = read;

	}
	else {//test == false
		//exit program and mark error at line number and element position
		error = true;
		cout << "Error on line " << lineNumber << " at position " << start << endl;
	}

}


//Function decides whether to tokenize keyword or mark error and exit program
void Automaton::evaluateKeyword(bool test, string line, int lineNumber, int& start, int& read, bool& error) {

	if (test == true) {
		//add to token list
		int lengthToRead = read - start +1; 
		string subStr = line.substr(start, lengthToRead);
		lexem->addKeywordToken(subStr, lineNumber, start);

		//increment read to the next char to be read in the next driver loop
		read++;

		//set start to catch up to read so the next lexem can be taken 
		start = read;

	}
	else {//test == false
		//exit program and mark error at line number and element position
		error = true;
		cout << "Error on line " << lineNumber << " at position " << start << endl;
	}

}


//Function decides whether to tokenize num or mark error and exit program
void Automaton::evaluateNum(bool test, string line, int lineNumber, int& start, int& read, bool& error) {

	if (test == true) {
		//add to token list
		int lengthToRead = read - start + 1;
		string subStr = line.substr(start, lengthToRead);
		lexem->addNumToken(subStr, lineNumber, start);

		//increment read to the next char to be read in the next driver loop
		read++;

		//set start to catch up to read so the next lexem can be taken 
		start = read;

	}
	else {//test == false
		//exit program and mark error at line number and element position
		error = true;
		cout << "Error on line " << lineNumber << " at position " << start << endl;
	}

}