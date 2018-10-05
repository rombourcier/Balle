#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <vector>

class Balle: public sf::CircleShape
{
	
public:
	using CircleShape::getPosition;
	using CircleShape::setPosition;
	Balle(sf::Color Color, float size);
	void ChangementDeSens();
	void CollisionI();
	void CollisionJ(Balle Rencontre);
	~Balle();
	void  setBallePos();
	
//	sf::Vector2f getDirection() override;
private:
	double angle;
	sf::Vector2f speed;
	std::vector <float> Pos = { 0,0 };
	std::vector <float> Deplacement = { 10,10 };
	
};

