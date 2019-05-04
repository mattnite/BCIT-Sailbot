// Vector class for sphere surface
//
// Author: Matthew Knight
// File Name: vector.cpp
// Date: 2019-04-26

#include "vector.hpp"
#include "point.hpp"

namespace Sailbot::Navigation {
	Vector::Vector(double heading, double theta) 
		: heading(heading), theta(theta) {}

	Point Vector::operator+(const Point& point) {}

	void Vector::rotate(double theta) {}
}
