
#include <iostream>
#include <fstream>
#include <string>


#include "Scanner.h"

using namespace std;



int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		cout << "Parameters not entered correctley" << endl;
		return -1;
	}


	string fileName = argv[1];
	
	//string fileName = "testArithmatic.txt";
	bool error = false;
	Scanner a = Scanner(fileName);
	a.driver(error);

	if (error == false) {
		a.next();
		while (a.kind() != "END") {

			cout << "Position: " << a.position() << endl;
			cout << "Kind: " << a.kind() << endl;
			cout << "Value: " << a.value() << endl;
			cout << endl << endl;
			a.next();

		}
	}

	

	return 0;
}

