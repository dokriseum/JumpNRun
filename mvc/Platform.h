#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

/**
 * @brief Klasse für eine Plattform
 *
 */
class Platform {
public:
    /**
     * @brief Konstruktor, der die Textur und Position der Plattform setzt
     *
     * @param texture Die Textur, die für die Plattform verwendet wird
     * @param x Die X-Koordinate der Plattform
     * @param y Die Y-Koordinate der Plattform
     */
    Platform(const sf::Texture& texture, float x, float y);

    /**
     * @brief Zeichnet die Plattform auf das Fenster
     *
     * @param window Das Render-Fenster, in dem die Plattform gezeichnet wird
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Gibt die Begrenzungen (Bounds) der Plattform zurück
     *
     * @return sf::FloatRect Die Begrenzungen der Plattform
     */
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite; ///< Der Sprite der Plattform
};

#endif // PLATFORM_H
