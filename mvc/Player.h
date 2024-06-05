#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

/**
 * @brief Klasse für den Spieler
 *
 */
class Player {
public:
    /**
     * @brief Konstruktor, der die Textur des Spielers setzt
     *
     * @param texture Die Textur, die für den Spieler verwendet wird
     */
    Player(const sf::Texture& texture);

    /**
     * @brief Behandelt die Benutzereingaben für die Steuerung des Spielers
     *
     * @param event Das aktuelle Event
     */
    void handleInput(const sf::Event& event);

    /**
     * @brief Aktualisiert die Position und den Zustand des Spielers
     *
     */
    void update();

    /**
     * @brief Zeichnet den Spieler auf das Fenster
     *
     * @param window Das Render-Fenster, in dem der Spieler gezeichnet wird
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Gibt die Begrenzungen (Bounds) des Spielers zurück
     *
     * @return sf::FloatRect Die Begrenzungen des Spielers
     */
    sf::FloatRect getBounds() const;

    /**
     * @brief Setzt die Position des Spielers
     *
     * @param x Die X-Koordinate
     * @param y Die Y-Koordinate
     */
    void setPosition(float x, float y);

    /**
     * @brief Setzt die vertikale Geschwindigkeit des Spielers
     *
     * @param vy Die vertikale Geschwindigkeit
     */
    void setVelocityY(float vy);

    /**
     * @brief Gibt zurück, ob der Spieler springt
     *
     * @return true Wenn der Spieler springt
     * @return false Wenn der Spieler nicht springt
     */
    bool isJumping() const;

    /**
     * @brief Setzt den Springstatus des Spielers
     *
     * @param jump Der neue Springstatus
     */
    void setJumping(bool jump);

private:
    sf::Sprite sprite; ///< Der Sprite des Spielers
    sf::Vector2f velocity; ///< Die Geschwindigkeit des Spielers

    const float gravity = 0.5f; ///< Die Schwerkraft, die auf den Spieler wirkt
    const float jumpPower = -10.f; ///< Die Sprungkraft des Spielers
    const float playerSpeed = 3.f; ///< Die Bewegungsgeschwindigkeit des Spielers

    bool movingLeft; ///< Bewegt sich der Spieler nach links
    bool movingRight; ///< Bewegt sich der Spieler nach rechts
    bool jumping; ///< Springt der Spieler
};

#endif // PLAYER_H
