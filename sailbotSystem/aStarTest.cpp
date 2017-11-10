// A-star class testing

// Author: Matthew Knight
// File Name: aStarTest.cpp
// Date: 2017-08-09

#include <iostream>
#include <stack>
#include "aStar.hpp"
#include <png++/png.hpp>

int main(void)
{
    // Create Object list
    std::list<node> objects;

    for (int i = -5; i <= 5; i++)
    {
	node temp(i, 5);
	objects.push_back(temp);
    }

    // Pathfind
    aStar pathfind;
    pathfind.setEnd(0, 20);
    pathfind.setObj(objects);
    pathfind.run();
    std::stack<node> path = pathfind.getPath();
    
    // making the png
    png::image<png::rgb_pixel> image(128, 128);

    for (size_t y = 0; y < image.get_height(); y++)
    {
	for (size_t x = 0; x < image.get_width(); x++)
	{
	    image[y][x] = png::rgb_pixel(255, 255, 255);
	}
    }
    
    // printing path
    while (!path.empty())
    {
	std::array<int,2> pos = path.top().position();
	if (path.size() > 1)
	    image[-pos[1] + image.get_height()/2][pos[0] + image.get_width()/2]
	    = png::rgb_pixel(128, 128, 128);
	else
	    image[-pos[1] + image.get_height()/2][pos[0] + image.get_width()/2] = png::rgb_pixel(176, 23, 31);
	path.pop();
    }
    
    // printing objects
    for (std::list<node>::iterator it = objects.begin(); it != objects.end(); it++)
    {	
	std::array<int,2> pos = (*it).position();

	image[-pos[1] + image.get_height()/2][pos[0] + image.get_width()/2] =
	png::rgb_pixel(0,0,0);
    }

    // setting the start to be green
    image[image.get_height()/2][image.get_width()/2] = png::rgb_pixel(0,128,0);
    image.write("rgb.png");
}
