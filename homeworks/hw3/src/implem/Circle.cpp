/*
 * Circle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#include "../headers/Circle.h"

#include <iostream>
#include <vector>
#include <cmath>

Circle::Circle(vector<double> newSides) {
	sides = newSides;
	//ensures right amount of sides
	sideCount = sides.size() == 1;
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
	if(valid){ //valid circle
		perimeter = 2 * 3.1415 * sides[0];
		area = 3.1415 * sides[0] * sides[0];
	}
	else{ //invalid circle
		perimeter = -1.17;
		area = -1.17;
	}
}

Circle::~Circle() {
	sides.clear();
	sides.shrink_to_fit();
}

double Circle::getArea(){
	if(valid){
		return area;
	}
	else{
		cout << errorMessage << endl;
		return area;
	}
}

double Circle::getPerimeter(){
	if(valid){
		return perimeter;
	}
	else{
		cout << errorMessage << endl;
		return perimeter;
	}
}

string Circle::getErrorMessage(){
	return errorMessage;
}

