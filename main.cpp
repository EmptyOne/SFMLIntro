// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main(int argc, char* argv[])
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(960, 800), "Mole Munch");

	sf::Texture player;
	player.loadFromFile("../assets/test.png", sf::IntRect(128,64,64,64));
	sf::Sprite playerS(player);
	playerS.setPosition(64, 64);

	sf::Texture background;
	background.loadFromFile("../assets/text.png");
	sf::Sprite bg(background);

	sf::Texture vegetable;
	vegetable.loadFromFile("../assets/test.png", sf::IntRect(0, 130, 64, 64));
	sf::Sprite vegetableS(vegetable);
	vegetableS.setPosition(128, 128);
	sf::Sprite moveVeg(vegetable);
	moveVeg.setPosition(playerS.getPosition());

	int ammo = 0;
	sf::Time vegTimer = sf::seconds(0.01f);
	sf::Clock clock;
	float dT = 1.f / 60.f;
	float speed = 5.f;

	sf::FloatRect windowBox = bg.getGlobalBounds();
	sf::FloatRect boundingBox = playerS.getGlobalBounds();
	sf::FloatRect boundingBox2 = vegetableS.getGlobalBounds();
	sf::FloatRect vegBox = moveVeg.getGlobalBounds();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		
		window.clear(sf::Color(0xf, 0x2f, 0xf3, 0xff));
		
		bg.setPosition(0,0);
		window.draw(bg);

		

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerS.move(-0.5, 0);
			sf::Vector2f position = playerS.getPosition();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerS.move(0.5, 0);
			sf::Vector2f position = playerS.getPosition();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerS.move(0, -0.5);
			sf::Vector2f position = playerS.getPosition();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerS.move(0, 0.5);
			sf::Vector2f position = playerS.getPosition();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			moveVeg.move(4, 0);
			window.draw(moveVeg);

			dT = clock.restart().asSeconds();
			
		}
		

	
		if (boundingBox.intersects(boundingBox2))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				vegetableS.setPosition(-500, -500);
				ammo++;
			}
		}

		window.draw(vegetableS);
		window.draw(playerS);
	
		
		window.display();
	}

	return 0;
}
