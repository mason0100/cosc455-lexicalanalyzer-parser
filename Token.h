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
		string idValue = "NOT ID"; // for identity tokens
		

		//Postion Variables
		int lineNumber;
		int linePosition;// Position of first character of the lexem

		};

	vector<token> tokenList;
	

public:

	Token();
	void addNumToken(string numStr, int lineNum, int start);
	void addKeywordToken(string keywordStr, int lineNum, int start);
	void addIdentifierToken(string idStr, int lineNum, int start);
	void addEndOFDocToken();
	void printTokenList();

};//end Token class



