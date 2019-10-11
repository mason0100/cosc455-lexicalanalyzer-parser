
#include <iostream>
#include <fstream>
#include <string>


#include "Scanner.h"

using namespace std;



int main(int argc, char *argv[]) {
	
	/*if (argc != 2) {
		cout << "Parameters not entered correctley" << endl;
		return -1;
	}


	string fileName = argv[1];*/
	
	string fileName = "testBoolean.txt";
	bool error = false;
	Token token;
	Scanner a = Scanner(token,fileName);
	a.driver(error);

	if (error == false) {
		token.next();
		while (token.kind() != "END") {

			cout << "Position: " << token.position() << endl;
			cout << "Kind: " << token.kind() << endl;
			cout << "Value: " << token.value() << endl;
			cout << endl << endl;
			token.next();

		}
	}

	

	return 0;
}

