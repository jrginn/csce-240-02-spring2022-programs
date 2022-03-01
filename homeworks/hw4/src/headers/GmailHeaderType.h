/*
 * GmailHeaderType.h
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */

#ifndef GmailHeaderType_H_
#define GmailHeaderType_H_

#include "BaseEmailHeaderType.h"

#include<string>
#include<vector>
#include<fstream>
#include <regex>

using namespace std;

class GmailHeaderType : public BaseEmailHeaderType{
public:
	//constructors
	GmailHeaderType();
	GmailHeaderType(vector<string> textLines);
	//destructor
	virtual ~GmailHeaderType();
	//methods
	vector<string> getHeader();
	string searchValue(string type);
};



#endif /* GmailHeaderType_H_ */
