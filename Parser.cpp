#include "Parser.h"

//constructor
Parser::Parser(Token& temp) {
	tokenPtr = &temp;
}


//function to be called in Main
//returns true if accept boolean is true
void Parser::expression() {
	return booleanExpression();
}

//Evaluates a boolean expression 
void Parser::booleanExpression() {
	booleanTerm();
	while (tokenPtr->kind.compareTo(OR)) {
		tokenPtr->next();
	}
	//neds to be finished
}


//Returns true is token id of type ID
void Parser::identrifier() {
	if (tokenPtr->kind() == ID) {
		//true
		//this needs to be changed to make work properly
	}
	//else false
}


//***helper Functions***

//returns the next pointer in the token vector
Token::token Parser::nextToken() {
	return tokenPtr->next();
}


//
void Parser::accept(string temp) {
	if (tokenPtr->kind.compareTo(temp) == 0) {
		//not sure whether to just check for a syntax error 
		//or to check incremend the current token to be evaluated
	}
	else {
		acceptBool = false;
	}
}