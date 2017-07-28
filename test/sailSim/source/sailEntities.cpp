// SailSim Sprite objects

// Author: Matthew Knight
// File Name: sailEntities.cpp
// Date: 2017-07-28

// This header file contains the declarations of several entities that will be
// used in the wingsail simulation program.

#include <cmath>
#include "sailEntities.hpp"

// parameterized ctor polar
arrow::arrow(float magnitude, float convert, float angle, float x, float y, sf::Color color)
    : mag(magnitude)
    , k(convert)
    , width(6)
    , height(10)
    , stem(sf::Lines, 2)
    , head(sf::Triangles, 3)
    , color(color)
{
    // Initialize arrow shape
    stem[0].position = sf::Vector2f(0, 0);
    stem[1].position = sf::Vector2f(mag*k, 0);
    
    head[0].position = sf::Vector2f(mag*k - height, width/2);
    head[1].position = sf::Vector2f(mag*k, 0);
    head[2].position = sf::Vector2f(mag*k - height, -width/2);

    // Transform arrow
    setPosition(x, y);
    setRotation(angle);
}

// Set polar representation of arrow wrt its origin 
void arrow::setPolar(float magnitude, float angle)
{
    mag = magnitude;
    
    stem[1].position = sf::Vector2f(mag*k, 0);
    head[0].position = sf::Vector2f(mag*k - height, width/2);
    head[1].position = sf::Vector2f(mag*k, 0);
    head[2].position = sf::Vector2f(mag*k - height, -width/2);

    setRotation(angle);
}

// draw method
void arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    states.transform *= getTransform();
	
    target.draw(head, states);
    target.draw(stem, states);
}


// Parameterized ctor
wingSail::wingSail(float xPos, float yPos, float ang1, float ang2)
    : x(xPos)
    , y(yPos)
    , l1(150)
    , l2(30)
    , frame(sf::LinesStrip, 3)
{
    frame[0].position = sf::Vector2f(0, 0);
    frame[1].position = sf::Vector2f(l1, 0);
    frame[2].position = sf::Vector2f(l1 + l2, 0);

    setPosition(x, y);
    setState(ang1, ang2);
}

void wingSail::setState(float ang1, float ang2)
{
    frame[2].position = sf::Vector2f(l1 + l2*cos(ang2*M_PI/180), l2*sin(ang2*M_PI/180));	
    setRotation(ang1);
}

// draw method
void wingSail::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
	
    target.draw(frame, states);
}
