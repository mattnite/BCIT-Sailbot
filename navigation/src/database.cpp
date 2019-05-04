// Navigation Database
//
// Author: Matthew Knight
// File Name: databse.cpp
// Date: 2019-05-02

#include "database.hpp"

#include "point.hpp"
#include "polygon.hpp"

#include <filesystem>
#include <vector>
#include <map>

namespace Sailbot::Navigation {
	Database::Database(const std::vector<std::filesystem::path>& files) {}
	
	std::vector<Polygon*> Database::queryBox(const BoundingBox& box) {}

	bool Database::isWater(const Point& point) {}

	std::map<Point, bool> Database::makeWaterMap(
		const Point& center, 
		double spacing, 
		size_t width
	) {}
}
