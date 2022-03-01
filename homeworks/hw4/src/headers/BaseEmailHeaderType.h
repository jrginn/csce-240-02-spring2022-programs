/*
 * BaseEmailHeaderType.h
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */

#ifndef BaseEmailHeaderType_H_
#define BaseEmailHeaderType_H_

#include<string>
#include<vector>
#include<fstream>
#include <regex>

using namespace std;

class BaseEmailHeaderType {
protected:
	//instance variables
	vector<string> header;

public:
	//constructors
	BaseEmailHeaderType();
	BaseEmailHeaderType(vector<string> textLines);
	//destructor
	virtual ~BaseEmailHeaderType();
	//methods
	vector<string> getHeader();
	string searchValue(string type);
};



#endif /* BaseEmailHeaderType_H_ */
