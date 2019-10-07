
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Automaton.h"
#include "Token.h"
#include "Scanner.h"

using namespace std;

void testNumId();
void testId();

int main() {

	Automaton a;

	string str = "%a + 2~";
	int lineNum = 0;
	bool error = false;
	if(error == false){
		a.identifyChar(str, lineNum, error);
		a.lexem.printTokenList();
	}
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