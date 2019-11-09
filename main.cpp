
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include "Scanner.h"
#include "Parser.h"

using namespace std;



int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		cout << "Parameters not entered correctley" << endl;
		return -1;
	}

	string fileName = argv[1];
	
	//string fileName = "example.txt";

	//determins if Scanner evaluates true or false
	bool error = false;
	
	Token token;

	Scanner a = Scanner(token,fileName);
	a.driver(error);
	
	Parser x = Parser(token);

	
	bool result = x.startEvaluation();
	
	if (result == true) {
		cout << "File has passed the syntax test." << endl;
	}
	else {
		cout << "File has failed the syntax test." << endl;
	}
	

	return 0;
}

