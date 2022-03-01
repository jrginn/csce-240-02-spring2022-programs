/*
 * OutlookHeaderType.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */

#include <iostream>
#include <regex>
#include "../headers/OutlookHeaderType.h"

using namespace std;

OutlookHeaderType::OutlookHeaderType(){
	header = {};
}

OutlookHeaderType::OutlookHeaderType(vector<string> textLines){
	header = {};
	for(int i = 0; i < textLines.size(); i++){
		header.push_back(textLines[i]);
	}
}

OutlookHeaderType::~OutlookHeaderType() {
    header.clear();
    header.shrink_to_fit();
}

vector<string> OutlookHeaderType::getHeader() {
    return header;
}

string OutlookHeaderType::searchValue(string type){
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
