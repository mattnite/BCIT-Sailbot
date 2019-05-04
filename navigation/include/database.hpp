// Navigation Database
//
// Author: Matthew Knight
// File Name: databse.hpp
// Date: 2019-05-02

#pragma once

#include "polygon.hpp"

#include <filesystem>
#include <vector>
#include <map>

namespace Sailbot::Navigation {
	/**
	 * Naviagation Database
	 *
	 * This class takes shapefiles and transforms them into a useful database
	 * that allows us to check if a particular spot is land/sea for navigation
	 * purposes.
	 *
	 * In the future we could add more to the interface, like city locations, or
	 * named landmasses.
	 */
	class Database {
		/**
		 * Query for polygons who's bounding boxes overlap with another box
		 */
		std::vector<Polygon*> queryBox(const BoundingBox& box);

	public:
		/**
		 * Construct by giving the databse a bunch of shapefiles.
		 */
		Database(const std::vector<std::filesystem::path>& files);

		/**
		 * Check if point is land or sea (GPS coordinates)
		 */
		bool isWater(const Point& point);

		/**
		 * Get sampled area of land/sea detection. Assumes a square area
		 */
		std::map<Point, bool> makeWaterMap(
			const Point& center, 
			double spacing, 
			size_t width
		);
	};
}
