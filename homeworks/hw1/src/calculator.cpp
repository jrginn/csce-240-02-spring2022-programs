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
	string input_file_name = "data/input.txt";
	string output_file_name = "data/output.txt";
	string line;
	//creates file variables
	ifstream input_myfile(input_file_name);
	ofstream output_myfile(output_file_name);
	//errors handling incorrect file names
	/*if(input_myfile.bad()){
		string new_infile_name;
		cout << "Input the file name. " <<endl;
		cin >> new_infile_name;
		input_myfile.close();
		//input_myfile(new_infile_name);
	}*/
	if(input_myfile.is_open()){
		//takes input from file lines
		getline(input_myfile, line);
		string operation = line;
		getline(input_myfile, line);
		int x = stoi(line);
		getline(input_myfile, line);
		int y = stoi(line);
		int result;
		//checks operator
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
			input_myfile.close();
			output_myfile.close();
			return 0;
		}
		output_myfile << "The result of " << operation << " on " << x << " and " << y << " is below." << endl;
		output_myfile << result;
		input_myfile.close();
		output_myfile.close();
	}
}
