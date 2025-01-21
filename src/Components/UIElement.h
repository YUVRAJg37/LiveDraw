//
// Created by YUVRAJ on 06-01-2025.
//

#ifndef UIELEMENT_H
#define UIELEMENT_H
#include <optional>

namespace sf {
    class Event;
}

namespace sf {
    class RenderWindow;
}

class UIElement {
public:
    virtual ~UIElement() = default;

    virtual void HandInput(const std::shared_ptr<sf::RenderWindow>& window, const std::optional<sf::Event>& event) = 0;
    virtual void Draw(const std::shared_ptr<sf::RenderWindow>& window) = 0;
};


#endif //UIELEMENT_H
