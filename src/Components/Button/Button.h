//
// Created by YUVRAJ on 06-01-2025.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
#include <memory>

#include "../UIElement.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

class Button final : public UIElement {
    std::unique_ptr<sf::RectangleShape> ButtonShape;
    std::function<void()> OnClick;

public:
    Button(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f bounds = sf::Vector2f(1,1), sf::Color color = sf::Color::White);
    void HandInput(const std::shared_ptr<sf::RenderWindow>& window, const std::optional<sf::Event>& event) override;
    void Draw(const std::shared_ptr<sf::RenderWindow>& window) override;
    void SetOnClick(const std::function<void()>& onClick);
};



#endif //BUTTON_H
