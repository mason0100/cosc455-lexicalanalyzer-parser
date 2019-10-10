#pragma once

#include "Automaton.h"
#include"Token.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Scanner{

public:

	Token token;
	string fileName;
	Scanner(string tempFileName);

	int driver(bool &error);
	void next();
	string kind();
	string value();
	string position();
	

};//end Scanner class

