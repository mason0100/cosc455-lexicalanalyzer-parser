#pragma once

#include "Token.h"

class Parser{

public:

	

	//constructor
	Parser(Token &temp);

private:

	//pointer for token object
	Token* tokenPtr;


	//expression returns true if accept == true
	bool acceptBool = true;


	//Multi character keywords
	const string NUM = "NUM";
	const string ID = "ID";
	const string END = "END";
	const string OR = "or";
	const string AND = "and";
	const string NOT = "not";
	const string TRUE = "true";
	const string FALSE = "false";
	const string OPEN_PARENTHESES = "(";
	const string CLOSE_PARENTHESES = ")";


	//Single character keywords
	const string EQUALS = "=";
	const string LESSTHAN = "<";
	const string PLUS = "+";
	const string MINUS = "-";
	const string TIMES = "*";
	const string DIVIDE = "/";
	const string UNDERSCORE = "_";

	//Functions for Parser evaluation
public:
	bool expression();
private:
	void booleanExpression();
	void booleanTerm();
	void booleanFactor();
	void arithmeticExpression();
	void term();
	void factor();
	void literal();
	void booleanLiteral();
	void integerLiteral();
	void identrifier();

	//helper functions
	Token::token nextToken();
	void accept(string temp);

};

