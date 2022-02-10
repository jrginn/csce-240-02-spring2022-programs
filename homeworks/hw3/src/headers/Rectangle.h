/*
 * Rectangle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
public:
	Rectangle(vector<double> newSides);
	virtual ~Rectangle();
	double getArea();
	double getPerimeter();
	string getErrorMessage();
};

#endif /* RECTANGLE_H_ */
