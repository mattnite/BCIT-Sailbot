// This program reads a shapefile header

#include "endian.hpp"
#include "shape-type.hpp"
#include "polygon.hpp"

#include <fstream>
#include <iostream>
#include <functional>

uint32_t code, length, version;
double xMin, xMax, yMin, yMax, zMin, zMax, mMin, mMax;
ShapeType type;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Invalid number of arguments" << std::endl;
		exit(1);
	}
	std::string filename(argv[1]);
	std::cout << "opening: " << filename << std::endl;
	std::ifstream shp(filename, std::ios::binary | std::ios::in);

	extractEndian(Endian::Big, shp, code);
	shp.ignore(20);
	
	extractEndian(Endian::Big, shp, length);
	length *= 2;

	extractEndian(Endian::Little, shp, version);
	extractEndian(Endian::Little, shp, type);

	extractEndian(Endian::Little, shp, xMin);
	extractEndian(Endian::Little, shp, yMin);
	extractEndian(Endian::Little, shp, xMax);
	extractEndian(Endian::Little, shp, yMax);
	extractEndian(Endian::Little, shp, zMin);
	extractEndian(Endian::Little, shp, zMax);
	extractEndian(Endian::Little, shp, mMin);
	extractEndian(Endian::Little, shp, mMax);
	
	std::cout 
		<< "code: " << code << std::endl
		<< "length: " << length << std::endl
		<< "version: " << version << std::endl
		<< "shape type: " << type << std::endl
		<< "xMin: " << xMin << std::endl
		<< "xMax: " << xMax << std::endl
		<< "yMin: " << yMin << std::endl
		<< "yMax: " << yMax << std::endl
		<< "zMin: " << zMin << std::endl
		<< "zMax: " << zMax << std::endl
		<< "mMin: " << mMin << std::endl
		<< "mMax: " << mMax << std::endl;

	while (!shp.eof()) {
		Polygon p(shp);
		std::cout 
			<< "polygon:" << std::endl
			<< "\tnumber: " << p.getNumber() << std::endl
			<< "\tlength: " << p.getLength() << std::endl
			<< "\tparts: " << p.getNumParts() << std::endl
			<< "\tpoints: " << p.getNumPoints() << std::endl;
	}

	std::cout << "end: " << shp.tellg() << std::endl;
}
