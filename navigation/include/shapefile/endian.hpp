// Header for determining system endianness
//
// Author: Matthew Knight
// File Name: endian.hpp
// Date: 2019-04-24

#pragma once

#include <iostream>
#include <vector>

#include <algorithm>

namespace Sailbot::Navigation::ShapeFile {
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

	template <Endian endian, typename T>
	void extract(std::istream& is, T& val) {
		if (is.eof())
			throw std::runtime_error("cannot extract endian from stream, it's eof");

		if (endian == endianness) {
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

	template <Endian endian, typename T>
	void extract(std::vector<char>& buf, T& val) {
		if (buf.size() < sizeof(T))
			throw std::runtime_error("not enough space to extract from buffer");

		if (endian == endianness) {
			std::copy_n(buf.cbegin(), sizeof(T), reinterpret_cast<char*>(&val));
		} else {

		}

		buf.erase(buf.cbegin(), std::next(buf.cbegin(), sizeof(T)));
	}
}
