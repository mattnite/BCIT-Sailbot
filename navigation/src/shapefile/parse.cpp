// Shapefile parser functions
//
// Author: Matthew Knight
// File Name: parse.cpp
// Date: 2019-05-03

#include "shapefile/parse.hpp"

#include "shapefile/header.hpp"
#include "shapefile/record.hpp"
#include "polygon.hpp"

#include <filesystem>
#include <fstream>
#include <tuple>
#include <vector>

namespace Sailbot::Navigation::ShapeFile {
	std::tuple<Header, std::vector<Record>> parseShapeFile(
		const std::filesystem::path& path
	) {
		std::ifstream shapefile(path.string(), std::ios::binary | std::ios::in);

		Header header(shapefile);
		std::vector<Record> records;

		while (!shapefile.eof())
			records.emplace_back(shapefile);

		return std::make_tuple(header, records);
	}
}
