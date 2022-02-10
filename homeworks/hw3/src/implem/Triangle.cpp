/*
 * Triangle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#include "../headers/Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(vector<double> newSides) {
	sides = newSides;
	//ensures right amount of sides
	sideCount = sides.size() == 3;
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
	if(valid){ //valid triangle
		perimeter = sides[0] + sides[1] + sides[2];
		double s = perimeter / 2.0;
		area = sqrt((s) * (s-sides[0]) * (s-sides[1]) * (s-sides[2]));
	}
	else{ //invalid triangle
		perimeter = -1.17;
		area = -1.17;
	}
}

Triangle::~Triangle() {
	sides.clear();
	sides.shrink_to_fit();
}

double Triangle::getArea(){
	if(valid){
		return area;
	}
	else{
		cout << errorMessage << endl;
		return area;
	}
}

double Triangle::getPerimeter(){
	if(valid){
		return perimeter;
	}
	else{
		cout << errorMessage << endl;
		return perimeter;
	}
}

string Triangle::getErrorMessage(){
	return errorMessage;
}
