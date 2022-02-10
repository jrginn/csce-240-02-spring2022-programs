/*
 * Rectangle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#include <iostream>
#include "../headers/Rectangle.h"

using namespace std;

Rectangle::Rectangle(vector<double> newSides) {
	sides = newSides;
	//ensures right amount of sides
	sideCount = sides.size() == 2;
	//ensures all sides are positive
	allPos = true;
	for(int i = 0; i < sides.size(); i++){
		if(sides[i] <= 0){
			allPos = false;
		}
	}
	if(!sideCount && !allPos){
		errorMessage = "Incorrect amount of sides and a side is not positive";
	}
	else if(!sideCount){
		errorMessage = "Incorrect amount of sides";
	}
	else if(!allPos){
		errorMessage = "A side is not positive";
	}
	else{
		errorMessage = "No errors";
	}
	valid = sideCount && allPos;
	if(valid){
		perimeter = 2 * (sides[0] + sides[1]);
		area = sides[0] * sides[1];
	}
	else{ //invalid rectangle
		perimeter = -1.17;
		area = -1.17;
	}
}

Rectangle::~Rectangle() {
	sides.clear();
	sides.shrink_to_fit();
}

double Rectangle::getArea(){
	if(valid){
		return area;
	}
	else{
		cout << errorMessage << endl;
		return area;
	}
}

double Rectangle::getPerimeter(){
	if(valid){
		return perimeter;
	}
	else{
		cout << errorMessage << endl;
		return perimeter;
	}
}

string Rectangle::getErrorMessage(){
	return errorMessage;
}

