// Simulation GPS Module
//
// Author: Matthew Knight
// File Name: sim-gps.hpp
// Date: 2019-04-12

#pragma once

#include "gps.hpp"

namespace Sailbot {
	/**
	 *
	 */
	class SimGps : public Gps {
	public:
		SimGps(Bridge& bridge);
	};
}
