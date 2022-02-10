/*
 * 240OOShapes.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: jrgin
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "headers/Shape.h"
#include "headers/Rectangle.h"
#include "headers/Triangle.h"
#include "headers/Circle.h"

using namespace std;


int main(int argc, char *argv[]){
	char command = *argv[1];
	if(command != '1' && command != '2'){
		cout << "Invalid command" << endl;
		return 1;
	}
	//initializes string names, delimiter, and line variable
	string infile_name = "data/input.txt";
	string outfile_name = "data/output.txt";
	string delimiter = " ";
	string line;
	//initializes index of spaces
	int space_index = 0;
	//initializes vectors to store sides
	vector<double> tri_sides;
	vector<double> cir_sides;
	vector<double> rec_sides;
	//creates file variables
	ifstream input_myfile(infile_name);
	ofstream output_myfile(outfile_name);
	//ensures input file exists
	if(input_myfile.bad()){
		cout << "Invalid file" << endl;
		return 1;
	}
	//rectangle
	getline(input_myfile, line);
	space_index = line.find(delimiter);
	if(line.substr(0,space_index).compare("Rectangle") != 0){
		cout << "Invalid order of shapes" << endl;
		return 1;
	}
	//removes shape name from line
	line = line.substr(space_index+1);
	while(line.find(delimiter) <= line.length()){
		try{
			rec_sides.push_back(stod(line.substr(0, line.find(delimiter))));
		}
		catch (const invalid_argument& ia){
			cout << "Not a number" << endl;
		}
		space_index = line.find(delimiter);
		line = line.substr(space_index+1);
	}
	if(line.length() == 0){
		cout << "Not enough sides" << endl;
	}
	else{
		try{
			rec_sides.push_back(stod(line));
		}
		catch (const invalid_argument& ia){
			cout << "Not a number" << endl;
		}
	}
	Rectangle rect(rec_sides);
	//circle
	line.clear();
	getline(input_myfile, line);
	space_index = line.find(delimiter);
	if(line.substr(0,space_index).compare("Circle") != 0){
		cout << "Invalid order of shapes" << endl;
		return 1;
	}
	//removes shape name from line
	line = line.substr(space_index+1);
	if(line.length() == 0){
		cout << "Not enough sides" << endl;
	}
	else{
		try{
			cir_sides.push_back(stod(line));
		}
		catch (const invalid_argument& ia){
			cout << "Not a number" << endl;
		}
	}
	Circle circ(cir_sides);
	//triangle
	line.clear();
	getline(input_myfile, line);
	space_index = line.find(delimiter);
	if(line.substr(0,space_index).compare("Triangle") != 0){
		cout << "Invalid order of shapes" << endl;
		return 1;
	}
	//removes shape name from line
	line = line.substr(space_index+1);
	while(line.find(delimiter) <= line.length()){
		try{
			tri_sides.push_back(stod(line.substr(0, line.find(delimiter))));
		}
		catch (const invalid_argument& ia){
			cout << "Not a number" << endl;
		}
		space_index = line.find(delimiter);
		line = line.substr(space_index+1);
	}
	if(line.length() == 0){
		cout << "Not enough sides" << endl;
	}
	else{
		try{
			tri_sides.push_back(stod(line));
		}
		catch (const invalid_argument& ia){
			cout << "Not a number" << endl;
		}
	}
	Triangle trian(tri_sides);
	if(command == '1'){ //area
		if(rect.getErrorMessage().compare("No errors") == 0){
			cout << "Rectangle area: " << rect.getArea() << endl;
			output_myfile << "Rectangle area: " << rect.getArea() << endl;
		}
		else{
			cout << rect.getErrorMessage() << endl;
			output_myfile << rect.getErrorMessage() << endl;
		}
		if(circ.getErrorMessage().compare("No errors") == 0){
			cout << "Circle area: " << circ.getArea() << endl;
			output_myfile << "Circle area: " << circ.getArea() << endl;
		}
		else{
			cout << circ.getErrorMessage() << endl;
			output_myfile << circ.getErrorMessage() << endl;
		}
		if(trian.getErrorMessage().compare("No errors") == 0){
			cout << "Triangle area: " << trian.getArea() << endl;
			output_myfile << "Triangle area: " << trian.getArea() << endl;
		}
		else{
			cout << trian.getErrorMessage() << endl;
			output_myfile << trian.getErrorMessage() << endl;
		}
	}
	else { //always equals 1 or 2 because of check at the beginning, so if not area then perimeter
		if(rect.getErrorMessage().compare("No errors") == 0){
			cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;
			output_myfile << "Rectangle perimeter: " << rect.getPerimeter() << endl;
		}
		else{
			cout << rect.getErrorMessage() << endl;
			output_myfile << rect.getErrorMessage() << endl;
		}
		if(circ.getErrorMessage().compare("No errors") == 0){
			cout << "Circle perimeter: " << circ.getPerimeter() << endl;
			output_myfile << "Circle perimeter: " << circ.getPerimeter() << endl;
		}
		else{
			cout << circ.getErrorMessage() << endl;
			output_myfile << circ.getErrorMessage() << endl;
		}
		if(trian.getErrorMessage().compare("No errors") == 0){
			cout << "Triangle perimeter: " << trian.getPerimeter() << endl;
			output_myfile << "Triangle perimeter: " << trian.getPerimeter() << endl;
		}
		else{
			cout << trian.getErrorMessage() << endl;
			output_myfile << trian.getErrorMessage() << endl;
		}
	}
	//closes files
	input_myfile.close();
	output_myfile.close();
}
