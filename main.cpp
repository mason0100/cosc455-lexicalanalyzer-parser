
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Automaton.h"
#include "Token.h"
using namespace std;

int main() {





	//creates file object
	//fstream myfile;

	//opens file
	//myfile.open("example.txt");

	//string variable for reading file 
	



	//str = "abcdefg   ";//3 white spaces
	//int test = 0; 
	//while (test < str.length()) {
	//	test++;
	//}


	


	
	Automaton automaton;
	//int start = 0;
	//int read = 0;

	////This while statement reads a .txt file line by line
	//while (getline(myfile, str)) {
	//	automaton.processWhiteSpace(str, start, read);
	//}
	//cout << "Start: " << start << endl;
	//cout << "Read : " << read << endl;
	//myfile.close();
	//return 0;
	Token token;

	cout << automaton.isUnderscore('c') << endl;
	cout << automaton.isUnderscore('_') << endl;
	cout << automaton.isUnderscore('p') << endl;
	cout << automaton.isUnderscore('-') << endl;


	cout << endl;

	string str = "012345";
	cout << str.at(0) << endl;
	cout << str.at(1) << endl;
	cout << str.at(2) << endl;
	cout << str.at(3) << endl;
	cout << str.at(4) << endl;
	cout << str.at(5) << endl;
}



