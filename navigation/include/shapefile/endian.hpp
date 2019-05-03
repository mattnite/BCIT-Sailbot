// Header for determining system endianness
//
// Author: Matthew Knight
// File Name: endian.hpp
// Date: 2019-04-24

#pragma once

#include <iostream>

enum class Endian {
	Big,
	Little
};

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
const Endian endianness = Endian::Big;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
const Endian endianness = Endian::Little;
#else
	#error invaid endianness
#endif

template <typename T>
void extractEndian(Endian endian, std::istream& is, T& val) {
	if (is.eof())
		throw std::runtime_error("cannot extract endian from stream, it's eof");

	if (endianness == endian) {
		is.read(reinterpret_cast<char*>(&val), sizeof(T));
	} else {
		T tmp;
		char* from = reinterpret_cast<char*>(&tmp);
		char* to = reinterpret_cast<char*>(&val);
		is.read(from, sizeof(T));
		
		for (int i = 0; i < sizeof(T); i++)
			to[i] = from[sizeof(T) - i - 1];
	}
}
