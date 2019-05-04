// Shapefile header class
//
// Author: Matthew Knight
// File Name: header.cpp
// Date: 2019-05-03

#include "shapefile/header.hpp"

#include "shapefile/endian.hpp"
#include "shapefile/shape-type.hpp"

namespace {
	const uint32_t expectedCode = 9994;
	const uint32_t expectedVersion = 1000;
	const Sailbot::Navigation::ShapeFile::ShapeType expectedType 
		= Sailbot::Navigation::ShapeFile::ShapeType::Polygon;
}

namespace Sailbot::Navigation::ShapeFile {
	Header::Header(std::istream& is) {
		extract<Endian::Big>(is, code);
		if (code != expectedCode)
			std::runtime_error("Shapefile code does not match");

		is.ignore(20);
		
		extract<Endian::Big>(is, length);
		// TODO: length check

		length *= 2;

		extract<Endian::Little>(is, version);
		if (version != expectedVersion)
			std::runtime_error("Shapefile version is not 1000");

		extract<Endian::Little>(is, type);
		if (type != expectedType)
			std::runtime_error("Shapefile type is not polygon");

		extract<Endian::Little>(is, box.tl.latitude);
		extract<Endian::Little>(is, box.br.longitude);
		extract<Endian::Little>(is, box.br.latitude);
		extract<Endian::Little>(is, box.tl.longitude);
		is.ignore(32);
	}
}
