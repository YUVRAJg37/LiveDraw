#include <SFML/Graphics.hpp>

#include "Components/UICollection/UICollection.h"
#include "Components/Button/Button.h"

int main()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({800u, 600u}), "Live-Draw"));
    window->setFramerateLimit(144);

    const auto collection = std::make_unique<UICollection>();

    const auto testButton = std::make_shared<Button>(sf::Vector2f(400, 300), sf::Vector2f(100, 100), sf::Color::Green);
    testButton->SetOnClick([](){std::cout<<"Button, Click\n";});

    collection->Push(testButton);

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }

            collection->Poll(window, event);
        }
        window->clear();

        collection->Draw(window);

        window->display();
    }
}
