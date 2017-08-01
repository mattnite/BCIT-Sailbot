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
    
    // Color
    stem[0].color = color;
    stem[1].color = color;
    
    head[0].color = color;
    head[1].color = color;
    head[2].color = color;

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

// Set arrow position
void arrow::setPos(float x, float y)
{
    setPosition(x, y);
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
    , mainForce(0, 1, 0, 0, 0, sf::Color::Red)
    , ailForce(0, 1, 0, l1, 0, sf::Color::Blue)
{
    frame[0].position = sf::Vector2f(0, 0);
    frame[1].position = sf::Vector2f(l1, 0);
    frame[2].position = sf::Vector2f(l1 + l2, 0);
    
    setPosition(x, y);
    setState(ang1, ang2);
}

// set member rotation
void wingSail::setState(float ang1, float ang2)
{
    float newX = l1 + l2*cos(ang2*M_PI/180);
    float newY = l2*sin(ang2*M_PI/180);
    frame[2].position = sf::Vector2f(newX, newY);
    ailForce.setPos(newX, newY);
    setRotation(ang1);
}

// set main force
void wingSail::setMain(float magnitude, float angle)
{
    mainForce.setPolar(magnitude, angle);
}

// set aileron force
void wingSail::setAil(float magnitude, float angle)
{
    ailForce.setPolar(magnitude, angle);
}

// draw method
void wingSail::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mainForce, states);
    target.draw(ailForce, states);
    target.draw(frame, states);
}
