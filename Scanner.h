#pragma once

#include "Automaton.h"
#include"Token.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Scanner{

public:

	Token* token;
	string fileName;
	Scanner(Token &tempToken, string tempFileName);
	int driver(bool &error);

};//end Scanner class

