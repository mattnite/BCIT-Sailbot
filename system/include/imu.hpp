// IMU Sensor Interface
//
// Author: Matthew Knight
// File Name: imu.hpp
// Date: 2019-03-23

#pragma once

#include "polling-thread.hpp"

#include <iostream>

namespace Sailbot {
	/**
	 * @brief IMU Interface
	 *
	 * The IMU sensor is assumed to be 3 axis, and measures values like
	 * orientation, acceleration, and heading.
	 *
	 * The purpose of the IMU is to measure these readings and report them to
	 * the Bridge.
	 */
	class Imu {
		PollingThread thread;

	public:
		using Heading = float;

		struct Acceleration {
			float x;
			float y;
			float z;
		};

		struct Orientation {};

		struct Data {
			Heading heading;
			Acceleration acceleration;
			Orientation orientation;
		};
		
		Imu(const std::chrono::milliseconds& period, std::function<void()> cb) : thread(std::chrono::milliseconds(500), []() {
			std::cout << "hello" << std::endl;
		})
		{}


	};
}
