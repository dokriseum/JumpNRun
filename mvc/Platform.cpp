#include "Platform.h"

Platform::Platform(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setScale(0.2f, 0.2f);  // Passe die Größe der Plattform an
    sprite.setPosition(x, y);
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Platform::getBounds() const {
    return sprite.getGlobalBounds();
}
