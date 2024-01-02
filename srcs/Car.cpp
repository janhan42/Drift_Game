/**
 * @file Car.cpp
 * @author jang hun han (wkdgns720@naver.com)
 * @brief
 * @version 0.1
 * @date 2024-01-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Car.hpp"
#include "DriftGame.hpp"
#include "SFML/System/Vector2.hpp"

Car::Car(float pos_x, float pos_y, sf::Color color)
: vel(0.0f, 0.0f), acceleration(0.0f, 0.0f), angle(0), angularVelocity(0)
{
	mass = 1160.0f;
	gravity = 9.8f;
	enginForce = 400.0f;
	drag = 0.70f;
	size.x = 50;
	size.y = 120;
	pos.x = pos_x;
	pos.y = pos_y;
	carBody.setSize(size);
	carBody.setPosition(pos);
	carBody.setFillColor(color);
}

void	Car::setPos(float pos_x, float pos_y)
{
	pos.x = pos_x;
	pos.y = pos_y;
	carBody.setPosition(pos);
}

void	Car::setVel(float vel_x, float vel_y)
{
	vel.x = vel_x;
	vel.y = vel_y;
}

sf::Vector2f	Car::getPos()
{
	return pos;
}

sf::Vector2f	Car::getVel()
{
	return vel;
}

void	Car::update(float deltaTime)
{
	acceleration.x = enginForce / mass - drag * vel.x / mass;
	acceleration.y = enginForce / mass - drag * vel.y / mass;

	vel = vel + acceleration * deltaTime;
	pos = pos + vel * deltaTime;

	if (pos.x < 0) {
        pos.x = 0;
        vel.x = 0; // 벽에 부딪혔으므로 속도를 0으로 설정
    }

    if (pos.x > SCREENWIDTH - carBody.getSize().x) {
        pos.x = SCREENWIDTH - carBody.getSize().x;
        vel.x = 0;
    }

    if (pos.y < 0) {
        pos.y = 0;
        vel.y = 0;
    }

    if (pos.y > SCREENHEIGHT - carBody.getSize().y) {
        pos.y = SCREENHEIGHT - carBody.getSize().y;
        vel.y = 0;
    }
	carBody.setPosition(pos);
}

void	Car::draw(sf::RenderWindow& window)
{
	window.draw(carBody);
}
