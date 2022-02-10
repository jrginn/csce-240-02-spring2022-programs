/*
 * Shape.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#include "../headers/Shape.h"

Shape::Shape() {
	sides = {1,1,1};
	errorMessage = "Invalid input";
	area = 1;
	perimeter = 3;
	allPos = true;
	sideCount = true;
}

Shape::Shape(vector<double> newSides){
	sides = newSides;
	errorMessage = "Invalid input";
	area = 1;
	perimeter = 1;
	allPos = true;
	sideCount = true;
}

Shape::~Shape() {
	sides.clear();
	sides.shrink_to_fit();
}
//default values for all of these
double Shape::getArea() {
	return 0.0;
}

double Shape::getPerimeter() {
	return 0.0;
}

string Shape::getErrorMessage(){
	return errorMessage;
}
