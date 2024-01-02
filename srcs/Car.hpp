/**
 * @file Car.hpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "DriftGame.hpp"

class Car
{
	public:
		Car(float pos_x, float pos_y, sf::Color color);
		void			setPos(float pos_x, float pos_y);
		void			setVel(float vel_x, float vel_y);
		sf::Vector2f	getPos();
		sf::Vector2f	getVel();
		void			update(float deltaTime);
		void			draw(sf::RenderWindow& window);

	private:
		sf::Vector2f		pos;
		sf::Vector2f		vel;
		sf::Vector2f		acceleration;
		float	angle;
		float	angularVelocity;
		float	enginForce;
		float	mass;
		float	drag;
		float	gravity;
		sf::RectangleShape	carBody;
		sf::Vector2f		size;
};
