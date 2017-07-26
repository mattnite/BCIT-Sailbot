// Wing Sail simulation program

// Author: Matthew Knight
// File Name: main.cpp
// Date: 2017-07-26

// This program a simple simulation of the sailbot wingsail. Wind Direction is
// always "south" while the speed can be changed along with the aileron
// position, both through up/down or left/right keys and will be displayed both
// numerically and with sliders.

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(480,640), "Wing Sail Sim");

    sf::Vertex line[] =
    {
	sf::Vertex(sf::Vector2f(10, 10)),
	sf::Vertex(sf::Vector2f(150, 150))
    };

    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}

	window.clear(sf::Color::Black);
	window.draw(line, 2, sf::Lines);
	window.display();
    }

    return 0;
}
