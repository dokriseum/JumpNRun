#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <vector>

/**
 * @brief Klasse für das Spielmanagement
 *
 */
class Game {
public:
    /**
     * @brief Konstruktor, der das Spiel initialisiert
     *
     */
    Game();

    /**
     * @brief Startet die Hauptspiel-Schleife
     *
     */
    void run();

private:
    /**
     * @brief Verarbeitet die Benutzereingaben und Events
     *
     */
    void processEvents();

    /**
     * @brief Aktualisiert den Zustand des Spiels
     *
     * @param deltaTime Die verstrichene Zeit seit dem letzten Frame
     */
    void update(sf::Time deltaTime);

    /**
     * @brief Rendert das Spiel auf dem Fenster
     *
     */
    void render();

    /**
     * @brief Lädt die benötigten Ressourcen (Texturen)
     *
     */
    void loadResources();

    /**
     * @brief Erstellt die Plattformen im Spiel
     *
     */
    void createPlatforms();

    sf::RenderWindow window; ///< Das Hauptfenster des Spiels
    sf::Texture backgroundTexture; ///< Die Textur für den Hintergrund
    sf::Texture playerTexture; ///< Die Textur für den Spieler
    sf::Texture platformTexture; ///< Die Textur für die Plattformen
    sf::Sprite backgroundSprite; ///< Der Sprite für den Hintergrund

    Player* player; ///< Zeiger auf den Spieler
    std::vector<Platform> platforms; ///< Vektor der Plattformen
};

#endif // GAME_H
