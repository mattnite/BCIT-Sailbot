// Sailbot Radio Interface
//
// Author: Matthew Knight
// File Name: radio.hpp
// Date: 2019-03-23

#pragma once

namespace Sailbot {
	/**
	 * @brief Radio Module Interface
	 *
	 * This class defines the interface for different radio implementations and
	 * how they are to communicate with the Bridge and Client.
	 *
	 * The implementations handle different communication mediums with the
	 * client. Initially this is expected to be an Xbee over serial, and either
	 * a message queue or socket for simulation.
	 *
	 * The Client and Radio communication exchange messages that are defined
	 * using Protobuf.
	 */
	class Radio {};
}
