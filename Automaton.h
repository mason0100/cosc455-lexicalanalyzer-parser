#pragma once
#include <string>
#include <iostream>
#include <string>


using namespace std;


class Automaton
{

public:
	Automaton();//constructor
	~Automaton();//Deconstructor
	void identifyChar(string line, int lineNumber);//Driver function
	

//private:

	bool isEqualsSymbol(string line, int& start, int& read);//keyword token
	bool isLessThanSymbol(string line, int& start, int& read);//keyword token
	bool isPlusSymbol(string line, int& start, int& read);//keyword token
	bool isMinusSymbol(string line, int& start, int& read);//keyword token
	bool isMultiplicationSymbol(string line, int& start, int& read);//keyword token
	bool isDivisionSymbol(string line, int& start, int& read);//keyword token
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

	//White space function
	void processWhiteSpace(string line, int &start, int &read);
};

