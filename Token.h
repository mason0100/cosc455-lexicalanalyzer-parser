#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;



//There are four token types in this language: identifier, num, keyword, endOfText
class Token{

private:
	
	//This will be the id table for identifier tokens
	//the index will be associate with the id number in the token stuct 
	vector<string> idTable;

	struct token {
		int idNumber; // the index of the created toke will be assigned to this value
		string tokenId; 
		
		//values
		int numValue; // for num tokens
		string strValue; // for identity tokens
		string keywordValue; // for keyword tokens
		int idTableIndex; // for identity 

		};

	vector<token> tokenList;

public:

	Token();
	void addNumToken(string numStr);
	void addKeywordToken(string keywordStr);
	void addIdentifierToken(string idStr);
	void addEndOFDocToken();
	void tokenListToString();

};//end Token class

