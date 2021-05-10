#include <SFML/Graphics.hpp>
#include "PSys.h"


using namespace std;
using namespace sf;


static const float VIEW_WIDTH = 600;
static const float VIEW_HEIGTH = 350;

int LevelId = 1;

void ResizeView(const RenderWindow& win, View& view)
{
    float aspectRatio = float(win.getSize().x) / float(win.getSize().y);
    float aspectRatio1 = float(win.getSize().y) / float(win.getSize().x);
    view.setSize(VIEW_HEIGTH * aspectRatio, VIEW_HEIGTH);
}


int main()
{
    //Drawing the window
    RenderWindow win(VideoMode(VIEW_WIDTH, VIEW_HEIGTH), "particle system");
    win.setFramerateLimit(60);
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_WIDTH, VIEW_HEIGTH));
    //******************
    int points = 0;
    //definining some variables
    float deltaTime = 0.0f, clocker = 0.0f;
    Clock clock;
    bool m_down = false;

    PSys p;




    //	********************

    while (win.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        if (deltaTime > 1.0f / 20.0f)
        {
            deltaTime = 1.0f / 20.0f;
        }
        Event e;
        //Managing events
        while (win.pollEvent(e))
        {
            switch (e.type)
            {
            case Event::Closed:
                win.close();
                break;
            case Event::MouseButtonPressed:
                m_down = true;
                break;
            case Event::MouseButtonReleased:
                m_down = false;
                break;
            case Event::Event::MouseMoved:
                if(m_down)
                    p.init(win);
                break;
            case Event::KeyPressed:
                switch (e.key.code)
                {
                case Keyboard::N:
                    win.close();
                    break;
                case Keyboard::O:
                    p.init(win);
                    break;
                }
                break;
            case Event::Resized:
                ResizeView(win, view);
                break;
            }
        }
        //********************
        p.Update();


        
        //Updating Animations

        //drawing on the window
        win.clear(Color(0, 0, 30, 255));

        p.Render(&win);
        win.display();

        //*************
    }
    return EXIT_SUCCESS;
}
