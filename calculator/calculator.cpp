//============================================================================
// Name        : calculator.cpp
// Author      : Jackson Ginn
// Version     :
// Copyright   : Your copyright notice
// Description : Calculator utilizing from files in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	// data/input
	string input_file_name = "data/input.txt";
	string output_file_name = "data/output.txt";
	string line;
	ifstream input_myfile (input_file_name);
	ofstream output_myfile(output_file_name);
	if(input_myfile.is_open()){
		getline(input_myfile, line);
		string operation = line;
		getline(input_myfile, line);
		int x = stoi(line);
		getline(input_myfile, line);
		int y = stoi(line);
		int result;
		if(operation.compare("add") == 0){
			result = x + y;
		}
		else if(operation.compare("subtract") == 0){
			result = x - y;
		}
		else if(operation.compare("multiply") == 0){
					result = x * y;
		}
		else if(operation.compare("divide") == 0){
					result = x / y;
		}
		else{
			cout << "Invalid operator" << endl;
		}
		output_myfile << "The result of " << operation << " on " << x << " and " << y << " is below." << endl;
		output_myfile << result;
	}
}
