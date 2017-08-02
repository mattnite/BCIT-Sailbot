# Sailbot Command Set

This document outlines the communication protocol with the sailbot. While the
competition rules seem to be consistent from year to year, there is no garantee
that they will stay the same. The command set is simple so that more complicated
behavior can be "scripted". 

The messages are intended to be transmitted over a Zigbee transciever or even a
satellite modem. Commands are framed in JSON, and can be converted to CBOR to
compress message length (and reduce cost in the case of the satellite modem).

| Command | Option  | Variables | Description |
| ------- | ------- | --------- | ----------- |
| Content | Content | Content   | Content     |
| Content | Content | Content   | Content     |
