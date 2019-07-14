//#include <TE/Core/TrueEngine.h>
//
//int main()
//{
//    /*sf::Image icon;
//    icon.loadFromFile("embercore.icon");
//
//    te::TrueEngine engine(te::VideoSettings(), "", icon);
//    try { 
//        engine.run();
//    }
//    catch(...) {
//        return 1;
//    }*/
//
//    return 0;
//}

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}