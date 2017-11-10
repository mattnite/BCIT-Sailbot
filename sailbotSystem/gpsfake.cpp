// Fake GPS Process

// Author: Matthew Knight
// File Name: gpsfake.cpp
// Date: 2017-08-11

// This program is used to provide fake gps coordinates for testing the sailbot
// system. White gaussian noise is added to the static coordinates.

#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    double earth_radius = 6.371e6;	// [m]
    
    double lat, lon;			// GPS coordinates
    double latStd, lonStd, std;		// Standard Deviations
    
    // GPS location from lower mainland
    lat = 49.00010234;
    lon = -123.0;
    std = 100.0;				// Typically GPS is +/- 5m

    latStd = std/earth_radius*180/M_PI;
    lonStd = std/(earth_radius*cos(lat*M_PI/180))*180/M_PI;

    // Noise Generation
    std::default_random_engine gen;
    std::normal_distribution<double> latNoise(0.0, latStd);
    std::normal_distribution<double> lonNoise(0.0, lonStd);

    // Initialize memory segment
    struct gps
    {
	double latitude;
	double longitude;
	double lat_err;
	double lon_err;
    };

    key_t key;
    int shmid;
    struct gps *data;
    int mode;

    // make they key
    if ((key = ftok(".gps", 'S')) == -1)
    {
	std::cerr << "Didn't get Key" << std::endl;
	return -1;
    }

    // connect and create memory segment
    if ((shmid = shmget(key, sizeof(struct gps), 0644 | IPC_CREAT)) == -1)
    {
	std::cerr << "Couldn't get memory segment" << std::endl;
	return -1;
    }

    // Attach pointer to segment
    data = (struct gps*)shmat(shmid, (void*) 0, 0);
    if (data == (struct gps*)(-1))
    {
	std::cerr << "Error with data" <<std::endl;
	return -1;
    }
    
    // Update memory segment periodically
    while (true)
    {
	data->latitude = lat + latNoise(gen);
	data->longitude = lon + lonNoise(gen);
	data->lat_err = latStd;
	data->lon_err = lonStd;
	
	std::cout
	    << std::setprecision(8)
	    << "Latitude: " << data->latitude << ", "
	    << "Longitude: " << data->longitude << std::endl;

	sleep(1);
    }
}
