/*
 * Triangle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jrgin
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {
public:
	Triangle(vector<double> newSides);
	virtual ~Triangle();
	double getArea();
	double getPerimeter();
	string getErrorMessage();
};

#endif /* TRIANGLE_H_ */
