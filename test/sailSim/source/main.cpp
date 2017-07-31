// Wing Sail simulation program

// Author: Matthew Knight
// File Name: main.cpp
// Date: 2017-07-26

// This program a simple simulation of the sailbot wingsail. Wind Direction is
// always "south" while the speed can be changed along with the aileron
// position, both through up/down or left/right keys and will be displayed both
// numerically and with sliders.

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

#include "sailEntities.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(480,640), "Wing Sail Sim", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    float time = 0;
    wingSail sailbot(240, 320, 0, 30);

    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}
	
	sf::Time elapsed = clock.restart();
	time += elapsed.asSeconds();
	
	sailbot.setState(120*time, 200*time);

	window.clear(sf::Color::Black);
	window.draw(sailbot);
	window.display();

	sf::sleep(sf::milliseconds(33));
    }

    return 0;
}
