// Shapefile parser functions
//
// Author: Matthew Knight
// File Name: parse.hpp
// Date: 2019-05-03

#pragma once

#include "shapefile/header.hpp"
#include "shapefile/record.hpp"

#include <filesystem>
#include <tuple>
#include <vector>

namespace Sailbot::Navigation::ShapeFile {
	std::tuple<Header, std::vector<Record>> parseShapeFile(
		const std::filesystem::path& path
	);
}
