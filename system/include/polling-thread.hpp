// Polling thread object
//
// Author: Matthew Knight
// File Name: polling-thread.hpp
// Date: 2019-04-11

#pragma once

#include <condition_variable>
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

namespace Sailbot {
	/**
	 *
	 */
	class PollingThread {
		using Clock = std::chrono::steady_clock;

		std::thread thread;
		std::chrono::milliseconds period;
		std::function<void()> task;
		std::condition_variable cv;
		std::mutex mtx;

	public:
		PollingThread(
			const std::chrono::milliseconds& period,
			std::function<void()> task
		)
			: period(period)
			, task(task)
			, thread([&](){
				std::unique_lock<std::mutex> lock(mtx);
				Clock::time_point next = Clock::now();

				while(cv.wait_until(lock, next)) {
					task();
					while (next < Clock::now())
						next += period;
				}
			})
		{}

		~PollingThread() {
			cv.notify_one();
			thread.join();
		}
	}
}
