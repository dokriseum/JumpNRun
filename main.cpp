#include <SFML/Graphics.hpp>
#include <vector>

const float gravity = 0.5f;
const float jumpPower = -10.f;
const float playerSpeed = 3.f;  // Reduzierte Geschwindigkeit

class Player {
public:
    sf::Sprite sprite;
    sf::Vector2f velocity;

    Player(const sf::Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f);  // Passe die Größe des Spielers an
    }

    void jump() {
        if (velocity.y == 0) {
            velocity.y = jumpPower;
        }
    }

    void update() {
        velocity.y += gravity;
        sprite.move(0, velocity.y);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jump'n'Run Spiel");

    // Lade Texturen
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("pic/background.png")) {
        return -1;
    }
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("pic/player.png")) {
        return -1;
    }
    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("pic/platform.png")) {
        return -1;
    }

    // Hintergrund-Sprite
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Spieler erstellen
    Player player(playerTexture);
    player.sprite.setPosition(400.f, 300.f);

    // Plattformen erstellen
    std::vector<sf::Sprite> platforms;
    sf::Sprite platformSprite;
    platformSprite.setTexture(platformTexture);
    platformSprite.setScale(0.2f, 0.2f);  // Passe die Größe der Plattformen an

    platforms.push_back(platformSprite);
    platforms.back().setPosition(300.f, 500.f);

    platforms.push_back(platformSprite);
    platforms.back().setPosition(450.f, 400.f);

    platforms.push_back(platformSprite);
    platforms.back().setPosition(200.f, 300.f);

    platforms.push_back(platformSprite);
    platforms.back().setPosition(600.f, 200.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.sprite.move(-playerSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.sprite.move(playerSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        }

        player.update();

        // Kollisionserkennung mit Plattformen
        for (auto& platform : platforms) {
            if (player.sprite.getGlobalBounds().intersects(platform.getGlobalBounds()) && player.velocity.y > 0) {
                player.sprite.setPosition(player.sprite.getPosition().x, platform.getPosition().y - player.sprite.getGlobalBounds().height);
                player.velocity.y = 0;
            }
        }

        // Begrenze die Bewegung des Spielers auf den Bildschirm
        if (player.sprite.getPosition().x < 0) {
            player.sprite.setPosition(0, player.sprite.getPosition().y);
        }
        if (player.sprite.getPosition().x > 800 - player.sprite.getGlobalBounds().width) {
            player.sprite.setPosition(800 - player.sprite.getGlobalBounds().width, player.sprite.getPosition().y);
        }
        if (player.sprite.getPosition().y > 600 - player.sprite.getGlobalBounds().height) {
            player.sprite.setPosition(player.sprite.getPosition().x, 600 - player.sprite.getGlobalBounds().height);
            player.velocity.y = 0;
        }

        window.clear(sf::Color::White);

        window.draw(backgroundSprite);

        for (auto& platform : platforms) {
            window.draw(platform);
        }

        window.draw(player.sprite);
        window.display();
    }

    return 0;
}
