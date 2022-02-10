/*
 * Shape.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include<string>
#include<vector>

using namespace std;

class Shape {
protected:
	//instance variables
	vector<double> sides;
	double area;
	double perimeter;
	string errorMessage;
	bool sideCount;
	bool allPos;
	bool valid;

public:
	//constructors
	Shape();
	Shape(vector<double> newSides);
	//destructor
	virtual ~Shape();
	//methods
	double getArea();
	double getPerimeter();
	string getErrorMessage();
};



#endif /* SHAPE_H_ */
