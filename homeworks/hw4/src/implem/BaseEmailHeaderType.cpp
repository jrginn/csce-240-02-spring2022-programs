/*
 * BaseEmailHeaderType.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */

#include <iostream>
#include <vector>
#include <regex>
#include "../headers/BaseEmailHeaderType.h"

using namespace std;

BaseEmailHeaderType::BaseEmailHeaderType(){
	header = {};
}

BaseEmailHeaderType::BaseEmailHeaderType(vector<string> textLines){
	header = {};
	for(int i = 0; i < textLines.size(); i++){
		header.push_back(textLines[i]);
	}
}

BaseEmailHeaderType::~BaseEmailHeaderType() {
    header.clear();
    header.shrink_to_fit();
}

vector<string> BaseEmailHeaderType::getHeader() {
    return header;
}

string BaseEmailHeaderType::searchValue(string type){
	string ret = "no value"; //default value
	regex typePattern(type);
	for(int i = 0; i < header.size(); i++){
		int colonIndex = header[i].find(":");
		try{
			string lineType = header[i].substr(0,colonIndex);
			string value = header[i].substr(colonIndex+2);
			if(regex_match(lineType, typePattern)){
				return value;
			}
		}
		catch(exception& e){
			cout << e.what() << endl;
		}
	}
	return ret;
}
