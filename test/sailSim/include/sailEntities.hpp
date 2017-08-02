// SailSim Sprite objects

// Author: Matthew Knight
// File Name: sailEntities.hpp
// Date: 2017-07-27

// This header file contains the declarations of several entities that will be
// used in the wingsail simulation program.

#include <SFML/Graphics.hpp>
#include "sail.hpp"

class arrow : public sf::Drawable, public sf::Transformable
{
    float mag;
    float k;
    
    // Arrowhead
    float width;
    float height;

    sf::VertexArray stem, head;
    sf::Color color;

public:
    // default ctor
    arrow();

    // parameterized ctor polar
    arrow(float magnitude, float convert, float angle, float x, float y, sf::Color color);
    
    // Set polar representation of arrow wrt its origin 
    void setPolar(float magnitude, float angle);

    // Set position of arrow
    void setPos(float x, float y);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class wingSail : public sf::Drawable, public sf::Transformable, public sail
{
    float l1,l2, x, y;

    arrow mainForce, ailForce;
    sf::VertexArray frame;

public:
    // Parameterized ctor
    wingSail(float xPos, float yPos, float ang1, float ang2);

    void setState(float ang1, float ang2);

    // set Main force arrow
    void setMain(float magnitude, float angle);

    // set aileron force arrow
    void setAil(float magnitude, float angle);

private:
    // draw method
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
