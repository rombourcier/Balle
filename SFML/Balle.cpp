#include "Balle.h"




Balle::Balle(sf::Color Color, float size) 
{
	
	int StartX = rand() % 800;
	int StartY = rand() % 800;
	std::cout << StartX << " " << StartY << std::endl;
	this->CircleShape::CircleShape(size);
	this->CircleShape::setFillColor(Color);
	this->CircleShape::setPosition(StartX,StartY);
}

void Balle::ChangementDeSens()
{
	int random = rand()%2;
	if (random = 1)
	{
		if (this->getPosition().x > 800)
		{
			this->Deplacement[0] = -this->Deplacement[0]-2;
		}
		if (this->getPosition().x < 0)
		{
			this->Deplacement[0] = -this->Deplacement[0]-2;

		}
		if (this->getPosition().y > 800)
		{
			this->Deplacement[1] = -this->Deplacement[1]+2;

		}
		if (this->getPosition().y < 0)
		{
			this->Deplacement[1] = -this->Deplacement[1]+2;
		}
	}
	else
	{
		if (this->getPosition().x > 800)
		{
			this->Deplacement[0] = -this->Deplacement[0]-2;
		}
		if (this->getPosition().x < 0)
		{
			this->Deplacement[0] = -this->Deplacement[0]-2;

		}
		if (this->getPosition().y > 800)
		{
			this->Deplacement[1] = -this->Deplacement[1]+2;

		}
		if (this->getPosition().y < 0)
		{
			this->Deplacement[1] = -this->Deplacement[1]+2;
		}
	}
}

void Balle::CollisionI()
{
	int change = rand() % 2;
	if (change = 0)
	{
		this->Deplacement[0] = -this->Deplacement[0] + 2;
		this->Deplacement[1] = -this->Deplacement[1] + 2;
	}

	if (change = 1)
	{
		this->Deplacement[0] = -this->Deplacement[0] - 2;
		this->Deplacement[1] = -this->Deplacement[1] - 2;
	}
}


void Balle::CollisionJ(Balle Rencontre)
{

	this->Deplacement[1] = -Rencontre.Deplacement[1];
}

Balle::~Balle()
{
	
}

void Balle::setBallePos()
{

	Pos[0] = this->CircleShape::getPosition().x + (Deplacement[0]);
	Pos[1] = this->CircleShape::getPosition().y + (Deplacement[1]);
	printf("\n %f %f %f", Pos[0], this->CircleShape::getPosition().x, Deplacement[0]);
	this->CircleShape::setPosition(Pos[0], Pos[1]);
}

