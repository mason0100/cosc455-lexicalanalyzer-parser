#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;



//There are four token types in this language: identifier, num, keyword, endOfText
class Token{

private:
	
	

	struct token {
		int tokenPosition; // the index of the created toke will be assigned to this value
		string type; // ID , NUM , not, true , false , _ , +, -, / , * , + , <
		
		//values, only ID and NUM tokens will be assigned a value
		int numValue = -1; // for num tokens
		string idValue = "N/A"; // for identity tokens
		
		//Postion Variables
		int lineNumber;
		int linePosition;// Position of first character of the lexem
		};

	vector<token> tokenList;//list of tokens 

	//int for the next() function
	//initialized to negative one to prime first call to next
	int nextElement = -1;
	

public:

	Token();
	void addNumToken(string numStr, int lineNum, int start);
	void addKeywordToken(string keywordStr, int lineNum, int start);
	void addIdentifierToken(string idStr, int lineNum, int start);
	void addEndOFDocToken();
	void printTokenList();

	token next();//reads the next lexeme in the input file
	string kind();//returns the kind of the lexeme that was just read.
	string value();// returns the value of the lexeme (if it is an “ID” or a “NUM”)
	string position();//returns the position of the lexeme that was just read

};//end Token class



