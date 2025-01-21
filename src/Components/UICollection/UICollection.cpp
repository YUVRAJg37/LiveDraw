//
// Created by YUVRAJ on 21-01-2025.
//

#include "UICollection.h"

#include "../UIElement.h"

void UICollection::Push(const std::shared_ptr<UIElement>& element) {
    if(element != nullptr) {
        UIElements.push_back(element);
    }
}

void UICollection::Poll(const std::shared_ptr<sf::RenderWindow>& window, const std::optional<sf::Event>& event) {
    if(UIElements.empty()) return;

    for (const auto& element: UIElements) {
        element->HandInput(window, event);
    }
}

void UICollection::Draw(const std::shared_ptr<sf::RenderWindow>& window) {
    if(UIElements.empty()) return;

    for (const auto& element: UIElements) {
        element->Draw(window);
    }
}
