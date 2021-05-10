#include "PSys.h"

PSys::PSys()
{
}

PSys::~PSys()
{
}

void PSys::init(sf::RenderWindow& win)
{
	this->AddPrt(sf::Mouse::getPosition(win).x , sf::Mouse::getPosition(win).y );
}

void PSys::Update()
{
	for (int i = 0; i < this->particles.size(); i++)
	{
		particles[i].Update();
	}
}

void PSys::AddPrt(float x, float y)
{
	particles.push_back(Particle(x,y));
}

void PSys::Render(sf::RenderWindow* win)
{
	for (int i = 0; i < this->particles.size(); i++)
	{
		particles[i].Render(win);
	}
}
