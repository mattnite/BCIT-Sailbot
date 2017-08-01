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
#include <iostream>
#include "sailEntities.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(480,640), "Wing Sail Sim", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    float time = 0;

    float angle = 0, speed = 10;
    wingSail sailbot(240, 320, 0, 30);
    arrow wind(speed, 2, 90, 240, 50, sf::Color::Green);

    while (window.isOpen())
    {
	
	sf::Event event;
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
		case sf::Event::Closed:
		    window.close();
		    break;
		case sf::Event::KeyPressed:
		    switch (event.key.code)
		    {
			case sf::Keyboard::Right:
			    angle += 1;
			    break;
			case sf::Keyboard::Left:
			    angle -= 1;
			    break;
			case sf::Keyboard::Up:
			    speed += 1;
			    break;
			case sf::Keyboard::Down:
			    speed -= 1;
			    break;
			default:
			    break;
		    };

		    break;
		default:
		    break;
	    };
	
	}
	
	sf::Time elapsed = clock.restart();
	time += elapsed.asSeconds();
	

	if (angle > 20)
	    angle = 20;
	if (angle < -20)
	    angle = -20;

	if (speed > 50)
	    speed = 50;
	if (speed < 0)
	    speed = 0;
	
	sailbot.setState(20*time, -angle);
	sailbot.setAil(25, 45);
	sailbot.setMain(50, -45); 
	wind.setPolar(speed, 90);

	window.clear(sf::Color::Black);
	window.draw(sailbot);
	window.draw(wind);
	window.display();

	sf::sleep(sf::milliseconds(33));
    }

    return 0;
}
