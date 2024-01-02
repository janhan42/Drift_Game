/**
 * @file DriftGame.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "DriftGame.hpp"
#include "Car.hpp"

int	main(void)
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Drift Game");
	window.setFramerateLimit(60);
	Car player(500, 500, sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2f force(0.0f, 0.0f);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		player.update(0.1f);
		player.draw(window);
		window.display();
	}

	return (0);
}
