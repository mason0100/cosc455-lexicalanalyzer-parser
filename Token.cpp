#include "Token.h"



//could in the future make a constructor for each of the token types
Token::Token(){
	
}


// adds num token to the token list
void Token::addNumToken(string numStr,int lineNum, int start) {

	struct token temp;
	
	//The size of the array before adding the token to the token vector will be the element number after adding to vectot
	temp.tokenPosition = tokenList.size(); 

	//Assign type
	temp.type = "NUM";

	//Token Value for num
	temp.numValue = stoi(numStr);

	//Postion
	temp.lineNumber = lineNum;
	temp.linePosition = start;
	
	//add to vector
	tokenList.push_back(temp);
}


//add keyword token to the token list
void Token::addKeywordToken(string keywordStr, int lineNum, int start) {

	struct token temp;

	//The size of the array before adding the token to the token vector will be the element number after adding to vectot
	temp.tokenPosition = tokenList.size();

	//Assign type, this will be the keyword 
	temp.type = keywordStr;

	//Keyword token has no value

	//Postion
	temp.lineNumber = lineNum;
	temp.linePosition = start;

	//add to vector
	tokenList.push_back(temp);
	
}


// adds identifier token to the token list
void Token::addIdentifierToken(string idStr, int lineNum, int start) {

	struct token temp;

	//The size of the array before adding the token to the token vector will be the element number after adding to vectot
	temp.tokenPosition = tokenList.size();

	//Assign type
	temp.type = "ID";

	//Token Value for num
	temp.idValue = idStr;

	//Postion
	temp.lineNumber = lineNum;
	temp.linePosition = start;

	//add to vector
	tokenList.push_back(temp);

}


//End of Doc token
void Token::addEndOFDocToken() {

	struct token temp;

	//The size of the array before adding the token to the token vector will be the element number after adding to vectot
	temp.tokenPosition = tokenList.size();

	//Assign type
	temp.type = "END";

	//Token Value for num

	//Postion
	temp.lineNumber = NULL;
	temp.linePosition = NULL;

	//add to vector
	tokenList.push_back(temp);

}


//prints token list for testing
//name needs changed
void Token::printTokenList() {

	for (int i = 0; i < tokenList.size(); i++) {
		cout << "Token Position: " << tokenList[i].tokenPosition << endl;
		cout << "Token Type: " << tokenList[i].type << endl;
		cout << "Num Value: " << tokenList[i].numValue << endl;
		cout << "ID Value: " << tokenList[i].idValue << endl;
		cout << "Line Number: " << tokenList[i].lineNumber << endl;
		cout << "Line Position: " << tokenList[i].linePosition << endl;
		cout << endl << endl;
		
	}


}

