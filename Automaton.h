#pragma once
#include <string>
#include <iostream>
#include <string>


using namespace std;


class Automaton
{

public:
	Automaton();//constructor
	void identifyChar(string line, int lineNumber);

//private:
	
	bool isNumber(string line, int& start, int& read);
	bool isIdentifier(string line, int &start, int &read);
	bool isUnderscore(string line, int& start, int& read);
	bool isUnderscore(char token);//helper function
	bool isDigit(char token);//helper function
	bool isLetter(char token);//helper function
	void processWhiteSpace(string line, int &start, int &read);
};

