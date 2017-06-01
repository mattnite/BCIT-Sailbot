# Sailbot Design Overview

## Strategy

The main goal for the sailbot is to maximize points at the [International
Robotic Sailing Regatta](http://sailbot.org). The IRSR is made up of several
competitions (These images are the documentation):

- Manual Race
    Simple race demonstrating that sailbot can be controlled manually.

- Navigation
    Same course as manual race, but now the sailbot must navigate.
    automatically. Score is based on time.

- Station Keeping
    Sailbot must stay within a 40m x 40m square for 5 minutes, and then exit
    as quickly as possible. Score is based on time.

- Payload
    Add weight to sailbot and sail for 200m. Score is based on percent weight
    transported.

- Object Avoidance
    Travel 200m where an object is randomly introduced. The score is based on
    how succesfully the sailbot avoiids the obstacle and finished its course.

- Search
    The sailbot has an orange buoy within 100m. It must come within 5m and then
    station keep within a time limit.

- Endurance Race
    All sailbots race for up to 8 hours. Points are awarded on number of laps
    and number of hours of consecutive automated sailing.    

As a note, the highest score from the payload, object avoidance, and search
competitions is taken. The maximum possible points increases respectively so we
have focused efforts on completing the search competition.

So looking at the above we can assertain a couple of keys to success
    - Speed is key.
    - Computer vision is needed to find buoy for search competition.
    - Needs to be able to avoid other boats during endurance race.
    - Needs to preserve power in endurance race.

## Mechanical

### Wing Sail

We are using a self-trimming fixed wing sail to propel our ship through the
waters. One of the difficulties of sailing, and automating it is rigging, and to
bypass that (and make the mechanical control far easier) we can use a wing sail.
Along with this we get the advantages of better lift/drag ratio over that of a
traditional cloth sail, increased mechanical durability, and the ability to have
reverse thrust.

We will be utilizing an mechanism to control the aileron while keeping the
actuator attached to the deck of the hull. A video of an example is right
[here](https://vimeo.com/79511782). This gives us the ability to have the
main wing freespin, simplifying the design further.

The Wingsail frame and pivot is complete, it just needs a mylar sheel as a skin,
and the control mechanism for the aileron.

### Hull, Keel, Rudder

The hull, keel, and rudder will be designed by Brian and his capstone team for
their 2nd year Mech. Eng. Capstone project. We will be using a monohull design
and the requirement for maximum hull length is 2 meters (to give an idea on the
size).

By September they will need information regarding the characteristics of the
sail and space needed for electronics (most notably the batteries).

## Software

For ease of development we chose to use Linux for an OS. 

### ZeroMQ

There are many ways to structure the control system, and the current route is to
split tasks up into different processes, and use [ZeroMQ](http://zeromq.org/)
for inter process communication. The reasons for this is that it is far easier
to split development up for different users, and very easy to test. Additionally
as this project goes on, requirements may change, features may be added, and
this topology allows for easy additions and changes to be made to the system.

### Command Server

This is a black box right now, it the process that starts all the others,
interprests command data, and uses the pathfinding algorithm to make navigation
decisions.

### Communications Server

This process handles all the incoming and outgoing data. Commands from the user
are saved to a file so that they are stored in non-volatile memory. It will
stream back sensor data to the user and stream forward control values during
manual mode.

We intend to design a command protocol that is flexible and modular so that we
could write scripts for each challenge at the IRSR.

### Input/Output Interface servers

And using ZeroMQ, simple server processes will be made to interface with the
hardware. Another process only needs to request in order to get a sensor
reading, or send a value to output to the actuators.

### Kalman Filter

The accuracy of GPS coordinated are extremely precise and accurate in context of
the entire earth. The standard deviation is typically 3 meters, however when
one's application works in the tens of meters this has the potential to cause
problems. There are other methods to tighten this accuracy, but we settled on a
Kalman filter.

Kalman filters use different sensor signals in order to reduce gaussian noise.
By using this type of filter with our GPS unit and IMU, we will be able to
better approximate our global position. Here is a [decent
article.](http://bzarg.com/p/how-a-kalman-filter-works-in-pictures/)

Takashi Nakamura is researching kalman filters and several members of the
sailbot team are working with him.

### Pathfinding Algorithm

The most common thing the sailbot will do is go from point A to point B. Given a
grid, and some points that are lebeled as obstacles, a pathfinding algorithm
will be able to calculate the optimatal route to the destination. In application
we would be generating a set of coordinates to follow to get to our destination,
and periodically recalculating this course to account for environmental
variables pushing us off course.

### Power Management

This is a server that will be provide information on the state of the charge of
the batteries, the entire system can take this information and make decisions
appropriate to the charge available.

### Vision System

Considering that the buoys used in competition are round, consistent in colour,
and in size, I hypothesize that we should be able to approximate their position
relative to the sailbot with a camera. Using copenCV and knowing the optics of a
camera mounted to the front of the sailbot give us adequate tools to easily
locate and track down the buoy for the search competition.

## Electrical

### Controller

We are using a Beaglebone Green as our controller unit for the sailbot. It runs
Debian as an operating system and has more than enough processing ability for
our application. Additionally, it has a large amount of interfacing circuitry
(analog inputs, multiple serial ports, SPI, I2C, etc.) so additional hardware
will not be needed.

### Communication

Currently we have two 63mW Xbee transcievers (1 mile range). These units are
suitable for manual and automatic control. Additional to either sending remote
control signals or commands, we would be able to stream sensor data from the
sailbot.

For future aspirations past the competition, a satellite modem will be needed
for any sort of long range missions. An affordable modem ($250 range) is
available for use with the Iridium Satellite Network.

### Sensors

* GPS
* 9-Axis IMU (BNO055)
    * 3-Axis Accelerometer
    * 3-Axis Gyroscope
    * 3-Axis Magnetometer
* Anemometer
* Wind Vane
* Camera
* 360 Degree Lidar

### Actuators

We have two points of actuation for the mechanical design, the aileron on the
wingsail, and the rudder. Moving these will likely draw the most power and so
making that as efficient as possible is the goal.

Our best option is to then us a linear actuator. Linear actuators utilize a worm
gear drive that is driven by a DC motor. The beauty in this solution is that it
only requires power to move the actuator, once it is taken away, the position is
mechanically locked. This is also mechanically convenient for use with the
actuation mechanism for the aileron as discussed earlier.

### Power

While wind could be utilized for power, the most convenient, and most
mechanically robust is solar panels. The power system will simply consist of
solar panels, batteries, a charger, and an interface to the Beaglebone so that
it may make decisions based on available charge.
