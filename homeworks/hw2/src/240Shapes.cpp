//============================================================================
// Name        : 240Shapes.cpp
// Author      : Jackson Ginn
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]) {
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
	//initializes arrays/variables for shapes and perimeter and area variables
	double *rect_sides = new double[2];
	double radius = 0;
	double *tri_sides = new double[3];
	double rect_per = 0;
	double rect_area = 0;
	double circ_per = 0;
	double circ_area = 0;
	double tri_per = 0;
	double tri_area = 0;
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
	if(space_index > line.length()){ //invalid input
		cout << "Not enough information to calculate." << endl;
		output_myfile << "Insufficient information." << endl;
	}
	else{
		//cuts off "rectangle "
		line = line.substr(space_index+1);
		//adds first number to rectangle array
		rect_sides[0] = stod(line.substr(0, line.find(delimiter))); //index of next space or end of line
		space_index = line.find(delimiter);
		if(space_index > line.length()){ //invalid input
			cout << "Not enough information to calculate." << endl;
			output_myfile << "Insufficient information." << endl;
		}
		else{
			//cuts off first number and space and adds second number to rectangle array
			rect_sides[1] = stod(line.substr(space_index+1));
			if(command == '1'){ //area
				rect_area = rect_sides[0] * rect_sides[1];
				output_myfile << "Rectangle area: " << rect_area << endl;
				cout << "Rectangle area: " << rect_area << endl;
			}
			else if(command == '2'){ //perimeter
				rect_per = 2 * (rect_sides[0] + rect_sides[1]);
				output_myfile << "Rectangle perimeter: " << rect_per << endl;
				cout << "Rectangle perimeter: " << rect_per << endl;
			}
		}
	}
	//circle
	getline(input_myfile, line);
	space_index = line.find(delimiter);
	if(space_index > line.length()){ //invalid input
		cout << "Not enough information to calculate." << endl;
		output_myfile << "Insufficient information." << endl;
	}
	else{
		//cuts off "circle "
		line = line.substr(space_index+1);
		//sets radius to the number inputted
		radius = stod(line.substr(0, line.find(delimiter)));
		if(command == '1'){
			circ_area = radius * radius * 3.141592;
			output_myfile << "Circle area: " << circ_area << endl;
			cout << "Circle area: " << circ_area << endl;
		}
		else if(command == '2'){
			circ_per = 2 * radius * 3.141592;
			output_myfile << "Circle perimeter: " << circ_per << endl;
			cout << "Circle perimeter: " << circ_per << endl;
		}
	}
	//triangle
	getline(input_myfile, line);
	space_index = line.find(delimiter);
	if(space_index > line.length()){ //invalid input
		cout << "Not enough information to calculate." << endl;
		output_myfile << "Insufficient information." << endl;
		return 1; //triangle is last shape, so it can immediately end
	}
	else{
		//cuts off "triangle "
		line = line.substr(space_index+1);
		space_index = line.find(delimiter); //updates new space index to space after number
		tri_sides[0] = stod(line.substr(0,space_index)); //adds double form of input
	}
	if(space_index > line.length()){ //invalid input
		cout << "Not enough information to calculate." << endl;
		output_myfile << "Insufficient information." << endl;
		return 1; //triangle is last shape, so it can immediately end
	}
	else{
		//cuts off "triangle "
		line = line.substr(space_index+1);
		space_index = line.find(delimiter); //updates new space index to space after number
		tri_sides[1] = stod(line.substr(0,space_index)); //adds double form of input
	}
	if(space_index > line.length()){ //invalid input
		cout << "Not enough information to calculate." << endl;
		output_myfile << "Insufficient information." << endl;
		return 1; //triangle is last shape, so it can immediately end
	}
	else{
		//cuts off "triangle "
		line = line.substr(space_index+1);
		space_index = line.find(delimiter); //updates new space index to space after number
		tri_sides[2] = stod(line.substr(0,space_index)); //adds double form of input
	}
	tri_per = tri_sides[0] + tri_sides[1] + tri_sides[2];
	if(command == '1'){ //use heron's formula
		double s = tri_per / 2;
		tri_area = sqrt((s)*(s-tri_sides[0])*(s-tri_sides[1])*(s-tri_sides[2]));
		output_myfile << "Triangle area: " << tri_area << endl;
		cout << "Triangle area: " << tri_area << endl;
	}
	else if(command == '2'){
		output_myfile << "Triangle perimeter: " << tri_per << endl;
		cout << "Triangle perimeter: " << tri_per << endl;
	}
	//deletes
	delete[](rect_sides);
	delete[](tri_sides);
	return 0;
}
