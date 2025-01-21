//
// Created by YUVRAJ on 21-01-2025.
//

#ifndef UICOLLECTION_H
#define UICOLLECTION_H
#include <memory>
#include <optional>
#include <vector>

#include "SFML/Network/SocketHandle.hpp"


namespace sf {
   class Event;
}

namespace sf {
   class RenderWindow;
}

class UIElement;

class UICollection {
public:
   std::vector<std::shared_ptr<UIElement>> UIElements;

   void Push(const std::shared_ptr<UIElement>& element);
   void Poll(const std::shared_ptr<sf::RenderWindow>& window, const std::optional<sf::Event>& event);
   void Draw(const std::shared_ptr<sf::RenderWindow>& window);
};



#endif //UICOLLECTION_H
