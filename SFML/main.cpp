#include <SFML/Graphics.hpp>
#include "Balle.h"
#include <iostream>


int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	std::vector <Balle> VBalles;
	sf::CircleShape TRex();
	Balle Pere(sf::Color::Yellow, 10.f);
	Balle Mere(sf::Color::Yellow, 10.f);
	Balle MereJ(sf::Color::Yellow, 10.f);
	Balle MereJJ(sf::Color::Yellow, 10.f);
	Balle PereR(sf::Color::Red, 10.f);
	VBalles.push_back(Pere);
	VBalles.push_back(Mere);
	VBalles.push_back(MereJ);
	VBalles.push_back(MereJJ);
	VBalles.push_back(PereR);

	bool Create = true;
	sf::Clock clock;
	sf::Texture texture;
	if (!texture.loadFromFile("Lena_MeanFilter.bmp"));
	{

	}
	window.setFramerateLimit(30);
	double angle;
	while (window.isOpen())
	{
		window.clear();
		sf::Time elapsed = clock.getElapsedTime(); // remet le chrono a 0 , getelapsedtime donne le temps depuis le lancement;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		int sizeVector = VBalles.size();
		for (int i = 0; i < sizeVector; i++)
		{
			Create = true;
			VBalles[i].setBallePos();

			if (VBalles[i].getPosition().x > 800 || VBalles[i].getPosition().x < 0 || VBalles[i].getPosition().y > 800 || VBalles[i].getPosition().y < 0)
			{
				VBalles[i].ChangementDeSens();	
			}

			for (int j = 0; j < sizeVector; j++ && Create)
			{
				if (VBalles[i].getGlobalBounds().intersects(VBalles[j].getGlobalBounds()) && i != j)
				{
					VBalles[i].CollisionI();
					VBalles[j].CollisionJ(VBalles[i]);
					if (VBalles[i].getFillColor() == VBalles[j].getFillColor() && VBalles[j].getFillColor() == sf::Color::Yellow &&Create)
					{
						if(sizeVector<80)
						VBalles.push_back(Balle(sf::Color::Yellow, 10.f));
						Create = false;
					}

					if (VBalles[i].getFillColor() != VBalles[j].getFillColor() && Create)
						if (VBalles[i].getFillColor() == sf::Color::Yellow)
						{
							VBalles[i].setFillColor(sf::Color::Red);
						}
						if (VBalles[i].getFillColor() == sf::Color::Red)
						{
							VBalles[j].setFillColor(sf::Color::Red);
						}
						Create = false;
				}
				
			}
			if (VBalles[i].getPosition().x > 850 || VBalles[i].getPosition().x < -50 || VBalles[i].getPosition().y > 850 || VBalles[i].getPosition().y < -50) // On remet la boule au centre si elle sort
				VBalles[i].setPosition(400.f, 400.f);
			window.draw(VBalles[i]);
		}
		
		window.draw(VBalles[0]);	
		window.display();



		}

		return 0;
}
