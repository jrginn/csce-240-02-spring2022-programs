/*
 * EmailProgramExtractor.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: jrgin
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

#include "headers/BaseEmailHeaderType.h"
#include "headers/OutlookHeaderType.h"
#include "headers/GmailHeaderType.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 3){
		cout << "Invalid number of arguments" << endl;
		return 1;
	}
	//initializes basic variables
	const string gmail = "Gmail";
	const string outlook = "Outlook";
	string infile_name = "";
	string emailType = argv[1];
	string partName = argv[2];
	bool isGmail = false;
	//checks if first argument is gmail or outlook
	if(gmail.compare(emailType) == 0){
		infile_name = "data/example-gmail.txt";
		isGmail = true;
	}
	else if(outlook.compare(emailType) == 0){
		infile_name = "data/example-msemail.txt";
	}
	else{
		//if it is neither, it ends
		cout << "Invalid email type" << endl;
		return 1;
	}
	ifstream input_myfile(infile_name);
	//ensures input file exists
	if(input_myfile.bad()){
		cout << "Invalid file" << endl;
		return 1;
	}
	//puts each line into a vector to be used in the constructors
	vector<string> lines = {};
	string text = "";
	while(getline(input_myfile, text)){
		lines.push_back(text);
	}
	//creates respective objects and searches the type argument
	if(isGmail){
		GmailHeaderType gH(lines);
		string gVal = gH.searchValue(partName);
		if(gVal != "no value")
			cout << gVal << endl;
	}
	else{
		OutlookHeaderType oH(lines);
		string oVal = oH.searchValue(partName);
		if(oVal != "no value")
			cout << oVal << endl;
	}
	input_myfile.close();
}
