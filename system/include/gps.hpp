// GPS Interface
//
// Author: Matthew Knight
// Date: 2019-03-22
// File Name: gps.hpp

#pragma once

namespace Sailbot {
	/**
	* @brief GPS Interface Class
	*
	* This class provides the interface for different GPS implementations, this
	* is so that simulation or different implementations can be created and 
	* switched out easily.
	*
	* The purpose of a GPS module is to update the Bridge with the latest GPS
	* coordingates
	*/
	class Gps {
	public:
		struct Coordinates {
			double latitude;
			double longitude;
		}
	};
}
