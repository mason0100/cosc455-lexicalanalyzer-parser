#pragma once
#include <string>
#include <iostream>
#include <string>
#include "Token.h"


using namespace std;


class Automaton
{

public:
	Automaton();//constructor
	Automaton(Token &temp);//second construnctor
	~Automaton();//Deconstructor
	void tokenizeFile(string line, int lineNumber, bool &error);//Driver function

	//Print token list
	void printTokenList();

	//This method will be called in the scanner function driver
	//when the text document has been read
	void evaluateEndOfText();

	
private:
	Token* lexem;//pointer to the token that contains the list to be provided to parser

	bool isCommentSymbol(string line, int& start, int& read);//keyword token
	bool isSingleCharKeyword(string line, int& start, int& read);
	bool isSingleMuliCharKeyword(string line, int& start, int& read);


	bool isNumber(string line, int& start, int& read);//number token
	bool isIdentifier(string line, int &start, int &read);//identifier tokem

	bool isUnderscoreSymbol(string line, int& start, int& read);//keyword token
	
	//Helper functions
	bool isUnderscore(char token);//helper function
	bool isDigit(char token);//helper function
	bool isLetter(char token);//helper function
	bool isForwardSlash(char token);//helper functtion

	//White space and Tab function
	void processWhiteSpaceOrTab(string line, int &start, int &read);
	

	//Function decides whether to tokenize or mark error and exit program
	void evaluateIdentifier(bool test, string line, int lineNumber, int& start, int& read, bool &error);
	void evaluateKeyword(bool test, string line, int lineNumber, int& start, int& read, bool& error);
	void evaluateNum(bool test, string line, int lineNumber, int& start, int& read, bool& error);
	

	
};

