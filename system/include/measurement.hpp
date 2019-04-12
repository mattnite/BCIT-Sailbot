// Measurement Object
//
// Author: Matthew Knight
// File Name: measurement.hpp
// Date: 2019-04-11

#pragma once

namespace Sailbot {
	/**
	 * Measurement assignment tracker
	 *
	 * This object wraps around the template variable type and keeps a time
	 * point of the last time it was assigned to.
	 */
	template <typename T>
	class Measurement {
		using Clock = std::chrono::steady_clock;

		T value;
		Clock::time_point timestamp;

	public:

		Measurement(const T& val) : value(val), timestamp(Clock::now()) {}

		/**
		 * Value assignment
		 *
		 * New values can be assigned directly and the value and timestamp will
		 * be updated.
		 *
		 * There is potential for race conditions with this class, the user has
		 * been warned.
		 */
		Measurement<T>& operator=(const T& val) {
			timestamp = Clock::now();
			value = val;
			return *this;
		}

		/**
		 * Get the timestamp
		 */
		Clock::time_point getTimestamp() {
			return timestamp;
		}

		/**
		 * Implicit conversion to the value type.
		 */
		operator T() {
			return value;
		}
	};
}
