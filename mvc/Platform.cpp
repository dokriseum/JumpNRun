#include "Platform.h"

Platform::Platform(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setScale(1.5f, 0.2f);  // Passe die Größe der Plattform an (breiter)
    sprite.setPosition(x, y);
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Platform::getBounds() const {
    return sprite.getGlobalBounds();
}

void Platform::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Platform::move(float dx, float dy) {
    sprite.move(dx, dy);
}
