
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Automaton.h"
#include "Token.h"
using namespace std;

void testNumId();
void testId();

int main() {

	/////hahahahaha



	//creates file object
	fstream myfile;

	//opens file
	myfile.open("test.txt");

	//string variable for reading file 
	string str;



	while (getline(myfile, str)) {

		cout << str << endl;
	}
	//Automaton automaton;
	//int start = 0;
	//int read = 0;

	////This while statement reads a .txt file line by line
	//while (getline(myfile, str)) {
	//	automaton.processWhiteSpace(str, start, read);
	//}
	//cout << "Start: " << start << endl;
	//cout << "Read : " << read << endl;
	myfile.close();
	//return 0;



	//Token token;

	/*cout << automaton.isUnderscore('c') << endl;
	cout << automaton.isUnderscore('_') << endl;
	cout << automaton.isUnderscore('p') << endl;
	cout << automaton.isUnderscore('-') << endl;


	cout << endl;

	str = "012345";
	cout << str.at(0) << endl;
	cout << str.at(1) << endl;
	cout << str.at(2) << endl;
	cout << str.at(3) << endl;
	cout << str.at(4) << endl;
	cout << str.at(5) << endl;*/

	//testNumId();
	testId();
}

void testNumId() {

	Automaton a;

	int read = 0;
	int start = 0;
	string str;
	//cout << a.isTrue("true", start, read) << endl;
	//cout << a.isTrue("trui", start, read) << endl;


	// testinf for isNumber

	//201
	read = 0;
	start = 0;
	str = "201a23+344a";
	cout << a.isNumber(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	//12345
	read = 0;
	start = 0;
	str = "12345";
	cout << a.isNumber(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	//123999999999999
	read = 0;
	start = 0;
	str = "123999999999999q45";
	cout << a.isNumber(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	cout << endl;



}

void testId() {

	Automaton a;

	int read = 0;
	int start = 0;
	string str;
	//cout << a.isTrue("true", start, read) << endl;
	//cout << a.isTrue("trui", start, read) << endl;


	// testinf for isNumber

	//nothing
	read = 0;
	start = 0;
	str = "a201a23+344a";
	cout << a.isIdentifier(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	//q12345
	read = 0;
	start = 0;
	str = "q12345";
	cout << a.isIdentifier(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	//123999999999999
	read = 0;
	start = 0;
	str = "e123999999999_999q45";
	cout << a.isIdentifier(str, start, read) << endl;
	cout << str.substr(start, read + 1) << endl;

	cout << endl;

}