#include "Token.h"



//could in the future make a constructor for each of the token types
Token::Token(){

}
// adds num token to the token list
void Token::addNumToken(string numStr) {
	
	int numValue = stoi(numStr);
	
	struct token temp;
	temp.idNumber = tokenList.size(); //assignes the size to the id because after the temp token struct is added the provious size will equal the new index number
	temp.tokenId = numStr;
	temp.numValue = numValue;
	tokenList.push_back(temp);
}


//add keyword token to the token list
void Token::addKeywordToken(string keywordStr) {

	struct token temp;
	temp.idNumber = tokenList.size(); //assignes the size to the id because after the temp token struct is added the provious size will equal the new index number
	temp.tokenId = keywordStr;
	temp.keywordValue = keywordStr;
	tokenList.push_back(temp);
}


// adds identifier token to the token list
void Token::addIdentifierToken(string idStr) {

	struct token temp;
	temp.idNumber = tokenList.size(); //assignes the size to the id because after the temp token struct is added the provious size will equal the new index number
	temp.idTableIndex = idTable.size();// assing the size of the id because after the idTable is updated the current size will be the new index number
	idTable.push_back(idStr);//adds identifier to ID table
	tokenList.push_back(temp);//adds token to token list

}


//prints token list for testing
//name needs changed
void Token::tokenListToString() {

	for (int i = 0; i < tokenList.size(); i++) {
		cout << "Index: " << tokenList[i].idNumber << endl;
		cout << "Token ID: " << tokenList[i].tokenId << endl;
		cout << "Num Value " << tokenList[i].numValue << endl;
	}

}

