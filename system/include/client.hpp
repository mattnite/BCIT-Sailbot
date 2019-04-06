// Sailbot Client
//
// Author: Matthew Knight
// File Name: client.hpp
// Date: 2019-03-23

#pragma once

namespace Sailbot {
	/**
	 * @brief Sailbot Client
	 * 
	 * This class exposes controls to a human user of the sailbot. This includes
	 * switching between manual and auto mode, sending manual control, and
	 * issuing high level commands.
	 *
	 * It does this by communicating with it's counterpart, the radio module.
	 * This is a separate binary from the sailbot, so it is not derived into
	 * subclasses for xbee or simulation use, it is implemented in different
	 * programs.
	 *
	 * The client and radio exchange messages that are defined using Protobuf.
	 */
	class Client {};
}
