// Vector class for sphere surface
//
// Author: Matthew Knight
// File Name: vector.hpp
// Date: 2019-04-26

#pragma once

namespace Sailbot::Navigation {
	class Vector {
		friend Vector operator-(const Point& a, const Point& b);
		double heading;
		double theta;
	public:
		Vector(double heading, double theta) : heading(heading), theta(theta) {}

		Point operator+(const Point& point);

		void rotate(double t

	};
}
