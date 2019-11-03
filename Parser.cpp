#include "Parser.h"

//constructor
Parser::Parser(Token& temp) {
	tokenPtr = &temp;
}


//function to be called in Main
//returns true if accept boolean is true
bool Parser::expression() {
	booleanExpression();
	if (acceptBool == true) {
		return true;
	}
	return false;
}

//Evaluates a boolean expression 
void Parser::booleanExpression() {
	booleanTerm();
	while (tokenPtr->kind().compare(OR) == 0) {
		tokenPtr->next();
		booleanTerm();
	}
	//neds to be finished
}


//Evaluates booleanTerm
void Parser::booleanTerm() {
	booleanFactor();
	while (tokenPtr->kind().compare(AND) == 0) {
		tokenPtr->next();
		booleanFactor();
	}
}


//Evaluates booleanFactor
void Parser::booleanFactor() {
	if (tokenPtr->kind().compare(NOT) == 0) {
		tokenPtr->next();
	}
	arithmeticExpression();
	if (tokenPtr->kind().compare(EQUALS) == 0 || tokenPtr->kind().compare(LESSTHAN) == 0) {
		tokenPtr->next();
		arithmeticExpression();
	}
}


//Evaluates aritmeticExpression
void Parser::arithmeticExpression() {
	term();
	while (tokenPtr->kind().compare(PLUS) == 0 || tokenPtr->kind().compare(MINUS) == 0) {
		tokenPtr->next();
		term();
	}
}


//Evaluates term
void Parser::term() {
	factor();
	while (tokenPtr->kind().compare(TIMES) == 0 || tokenPtr->kind().compare(DIVIDE) == 0) {
		tokenPtr->next();
		factor();
	}
}


//Evaluates factor
void Parser::factor() {
	if (tokenPtr->kind().compare(TRUE) == 0 || tokenPtr->kind().compare(FALSE) == 0 || tokenPtr->kind().compare(NUM) == 0) {
		literal();
	}
	else if (tokenPtr->kind().compare(ID) == 0) {
		tokenPtr->next();
	}
	else if (tokenPtr->kind().compare(OPEN_PARENTHESES) == 0) {
		tokenPtr->next();
		expression();
		accept(CLOSE_PARENTHESES);
	}
	else {
		//mark as a syntax error
		acceptBool = false;
	}
}


//Evaluates literal
void Parser::literal() {
	if (tokenPtr->kind().compare(TRUE) == 0 || tokenPtr->kind().compare(TRUE) == 0 || tokenPtr->kind().compare(NUM) == 0) {
		tokenPtr->next();
	}
	else {
		//mark as error
		acceptBool = false;
	}
}



//***helper Functions***

//returns the next pointer in the token vector
Token::token Parser::nextToken() {
	return tokenPtr->next();
}


//
void Parser::accept(string temp) {
	if (tokenPtr->kind().compare(temp) == 0) {
		tokenPtr->next();
		
	}
	else {
		acceptBool = false;
	}
}