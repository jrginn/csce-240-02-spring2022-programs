/*
 * Circle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle: public Shape {
public:
	Circle(vector<double> newSides);
	virtual ~Circle();
	double getArea();
	double getPerimeter();
	string getErrorMessage();
};

#endif /* CIRCLE_H_ */
