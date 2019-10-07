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
	~Automaton();//Deconstructor
	void identifyChar(string line, int lineNumber, bool &error);//Driver function

	//Print token list
	void printTokenList();

	//This method will be called in the scanner function driver
	//when the text document has been read
	void evaluateEndOfText();

	void next();//Reads the next lexem
	string kind();//returns the kins of lexem that was just read
	string value();//returns the value of the lexeme (if it is an “ID” or a “NUM”).
	int position();// returns the position of the lexeme that was just read
	

private:
	Token lexem;//contains the token list to be proviced to parser

	bool isEqualsSymbol(string line, int& start, int& read);//keyword token
	bool isLessThanSymbol(string line, int& start, int& read);//keyword token
	bool isPlusSymbol(string line, int& start, int& read);//keyword token
	bool isMinusSymbol(string line, int& start, int& read);//keyword token
	bool isMultiplicationSymbol(string line, int& start, int& read);//keyword token
	bool isCommentSymbol(string line, int& start, int& read);//keyword token
	bool isDivisionSymbol(string line, int& start, int& read);
	bool isFalse(string line, int& start, int& read);
	bool isTrue(string line, int& start, int& read);
	bool isNot(string line, int& start, int& read);


	bool isNumber(string line, int& start, int& read);//number token
	bool isIdentifier(string line, int &start, int &read);//identifier tokem

	bool isUnderscoreSymbol(string line, int& start, int& read);//keyword token
	
	//Helper functions
	bool isUnderscore(char token);//helper function
	bool isDigit(char token);//helper function
	bool isLetter(char token);//helper function
	bool isForwardSlash(char token);//helper functtion

	//White space function
	void processWhiteSpace(string line, int &start, int &read);

	//Function decides whether to tokenize or mark error and exit program
	void evaluateIdentifier(bool test, string line, int lineNumber, int& start, int& read, bool &error);
	void evaluateKeyword(bool test, string line, int lineNumber, int& start, int& read, bool& error);
	void evaluateNum(bool test, string line, int lineNumber, int& start, int& read, bool& error);
	

	
};

