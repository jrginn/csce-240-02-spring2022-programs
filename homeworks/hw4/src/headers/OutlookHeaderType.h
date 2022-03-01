/*
 * OutlookHeaderType.h
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */

#ifndef OutlookHeaderType_H_
#define OutlookHeaderType_H_

#include "BaseEmailHeaderType.h"

#include<string>
#include<vector>
#include<fstream>
#include <regex>

using namespace std;

class OutlookHeaderType : public BaseEmailHeaderType{
public:
	//constructors
	OutlookHeaderType();
	OutlookHeaderType(vector<string> textLines);
	//destructor
	virtual ~OutlookHeaderType();
	//methods
	vector<string> getHeader();
	string searchValue(string type);
};



#endif /* OutlookHeaderType_H_ */
