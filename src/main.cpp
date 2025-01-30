#include <iostream>

#include <SFML/Graphics.hpp>
#include <Dwmapi.h>

#include "Components/UICollection/UICollection.h"
#include "Components/Button/Button.h"

void MakeWindowTransparent(const HWND& hwnd) {
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, 0, 50, LWA_ALPHA);
}

int main()
{
    const sf::Vector2<unsigned int> size = sf::VideoMode::getDesktopMode().size;
    const auto window = std::make_shared<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode(size), "Live-Draw"));

    window->setFramerateLimit(144);

    MakeWindowTransparent(window->getNativeHandle());

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
        window->clear(sf::Color::Transparent);

        collection->Draw(window);

        window->display();
    }
}
