#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(360, 640), "Tickets, Please", sf::Style::Close | sf::Style::Titlebar);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(115,115,140));
        window.display();
    }

    return 0;
}