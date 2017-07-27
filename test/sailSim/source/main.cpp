// Wing Sail simulation program

// Author: Matthew Knight
// File Name: main.cpp
// Date: 2017-07-26

// This program a simple simulation of the sailbot wingsail. Wind Direction is
// always "south" while the speed can be changed along with the aileron
// position, both through up/down or left/right keys and will be displayed both
// numerically and with sliders.

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
    arrow()
    {}

    // parameterized ctor polar
    arrow(float magnitude, float convert, float angle, float x, float y, sf::Color color)
	: mag(magnitude)
	, k(convert)
	, width(6)
	, height(10)
	, stem(sf::Lines, 2)
	, head(sf::Triangles, 3)
	, color(color)
    {
	// Initialize arrow shape
	stem[0].position = sf::Vector2f(0, 100);
	stem[1].position = sf::Vector2f(mag*k, 100);
	
	head[0].position = sf::Vector2f(mag*k - height, 100 + width/2);
	head[1].position = sf::Vector2f(mag*k, 100);
	head[2].position = sf::Vector2f(mag*k - height, 100 - width/2);

	// Transform arrow
    }
    
    // Set position
    void setPosition(float x, float y);
    
    // Set polar representation of arrow wrt its origin 
    void setPolar(float magnitude, float angle);


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

	states.transform *= getTransform();
	    
	target.draw(head, states);
	target.draw(stem, states);
    }
};


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(480,640), "Wing Sail Sim", sf::Style::Default, settings);
    
    arrow force(300, 1, 0, 50, 50, sf::Color::Red);

    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}

	window.clear(sf::Color::Black);
	window.draw(force);
	window.display();
    }

    return 0;
}
