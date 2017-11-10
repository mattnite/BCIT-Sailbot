# Sailbot Command Set

This document outlines the communication protocol with the sailbot. While the
competition rules seem to be consistent from year to year, there is no garantee
that they will stay the same. The command set is simple so that more complicated
behavior can be "scripted". 

The messages are intended to be transmitted over a Zigbee transciever or even a
satellite modem. Commands are framed in JSON, and can be converted to CBOR to
compress message length (and reduce cost in the case of the satellite modem).
Commands can be sent one at a time, or sent over as an array.

## Commands

### man

Put the sailbot into manual mode. Manual control is done by sending the rud and
thrust commands repeatedly. Any auto commands are valid, they will simply add to
the queue.

### auto

Put the sailbot into automatic mode. In this mode, rud and thrust commands are
ignored. The sailbot will process its command queue, and if the queue is empty
then it will simply stationkeep.

### rud

Set position of the rudder, it is represented by a floating point number from -1
to 1;

### thrust

Set thrust direction, it is either forward, neutral, or backwards.

### add

add waypoints, objects, or waits. Waypoints and objects are defined by GPS
coordinates. Wait commands are simply waypoint commands that come with a time
argument. This argument indicates how long the sailbot will stationkeep at the
waypoint before continuing the command queue.

### clear

Clear queues or lists. The options are commands, objects, or all.
