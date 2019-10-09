#pragma once

#include "Automaton.h"
#include"Token.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Scanner{

public:


	string fileName;

	Scanner(string tempFileName);

	int driver();
	

};//end Scanner class

