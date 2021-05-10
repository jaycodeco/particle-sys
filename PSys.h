#pragma once

#include "Particle.h"
#include<vector>

class PSys
{
public:
	PSys();
	~PSys();

	void init(sf::RenderWindow& win);
	void Update();
	void AddPrt(float x, float y);
	void Render(sf::RenderWindow* win);

private:
	std::vector<Particle> particles;
	sf::Vector2f pos;
};

