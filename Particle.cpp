#include "Particle.h"

Particle::Particle(float x, float y)
{
    this->R = 0;
    this->G = 0;
    this->B = 0;
    this->body.setSize(sf::Vector2f(2, 2));
    this->body.setPosition(x, y);
    this->body.setFillColor(sf::Color(R, G, B, 255));
}

Particle::~Particle()
{
}

void Particle::Update()
{
    this->body.setFillColor(sf::Color(this->R++, this->G++, this->B++, 255));

    if (R == 256)
    {
        this->R = 0;
        this->G = 0;
        this->B = 0;
    }
    
    this->body.move(0,1);
}

void Particle::Render(sf::RenderWindow* win)
{
    win->draw(body);
}
