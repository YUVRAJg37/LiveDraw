//
// Created by YUVRAJ on 06-01-2025.
//

#include "Button.h"

#include "SFML/Graphics/RenderWindow.hpp"

Button::Button(sf::Vector2f position, sf::Vector2f bounds, sf::Color color) {
    ButtonShape = std::make_unique<sf::RectangleShape>();
    ButtonShape->setPosition(position);
    ButtonShape->setSize(bounds);
    ButtonShape->setFillColor(color);
}

void Button::HandInput(const std::shared_ptr<sf::RenderWindow>& window, const std::optional<sf::Event>& event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    if (ButtonShape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && OnClick) {
        if(const auto& mouseButton =  event->getIf<sf::Event::MouseButtonPressed>()) {
            if(mouseButton->button == sf::Mouse::Button::Left) {
                OnClick();
            }
        }
    }
}

void Button::Draw(const std::shared_ptr<sf::RenderWindow>& window) {
    window->draw(*ButtonShape);
}

void Button::SetOnClick(const std::function<void()> &onClick) {
    OnClick = onClick;
}
