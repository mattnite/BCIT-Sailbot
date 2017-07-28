// SailSim Sprite objects

// Author: Matthew Knight
// File Name: sailEntities.hpp
// Date: 2017-07-27

// This header file contains the declarations of several entities that will be
// used in the wingsail simulation program.

#include <SFML/Graphics.hpp>

class arrow : public sf::Drawable, sf::Transformable
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

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
