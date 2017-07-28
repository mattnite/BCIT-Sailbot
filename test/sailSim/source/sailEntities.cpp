// SailSim Sprite objects

// Author: Matthew Knight
// File Name: sailEntities.cpp
// Date: 2017-07-28

// This header file contains the declarations of several entities that will be
// used in the wingsail simulation program.

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
