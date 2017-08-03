// SailSim Sprite objects

// Author: Matthew Knight
// File Name: sailEntities.hpp
// Date: 2017-07-27

// This header file contains the declarations of several entities that will be
// used in the wingsail simulation program.

#include <complex>
#include <SFML/Graphics.hpp>
#include "sail.hpp"

class arrow : public sf::Drawable, public sf::Transformable
{
    double mag;
    double k;
    
    // Arrowhead
    double width;
    double height;

    sf::VertexArray stem, head;
    sf::Color color;

public:
    // default ctor
    arrow();

    // parameterized ctor polar
    arrow(double magnitude, double convert, double angle, double x, double y, sf::Color color);
    
    // Set polar representation of arrow wrt its origin 
    void setPolar(double magnitude, double angle);

    // Set position of arrow
    void setPos(double x, double y);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class wingSail : public sf::Drawable, public sf::Transformable, public sail
{
    double l1,l2, x, y;

    arrow mainForce, ailForce;
    sf::VertexArray frame;

public:
    // Parameterized ctor
    wingSail(double xPos, double yPos, double ang1, double ang2);

    // Update real time simulation of wingsail
    void process(std::complex<double>& windVect, double ailAngle, double time);

private:
    // set angular positions of members
    void setState(double ang1, double ang2);

    // set Main force arrow
    void setMain(double magnitude, double angle);

    // set aileron force arrow
    void setAil(double magnitude, double angle);
    
    // draw method
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
