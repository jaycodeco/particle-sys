#pragma once


#include<SFML/Graphics.hpp>
#include<stdint.h>

class Particle
{
public:
	Particle(float x, float y);
	~Particle();

	void Update();
	void Render(sf::RenderWindow* win);


private:
	sf::RectangleShape body;
	int R;
	int G;
	int B;
};

