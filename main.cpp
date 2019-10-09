
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
	
	//string fileName = "";
	
	Scanner a = Scanner(fileName);
	a.driver();




	return 0;
}

