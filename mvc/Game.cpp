#include "Game.h"
#include <iostream>
#include <random>
#include "pic/background.h"
#include "pic/player.h"
#include "pic/platform.h"

Game::Game()
        : window(sf::VideoMode(800, 600), "Jump'n'Run Spiel"), player(nullptr), score(0), scrollSpeed(100.f), scrollOffset(0.f) {
    loadResources();
    createPlatforms();
    player = new Player(playerTexture);
    player->setPosition(400.f, 300.f);

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
            window.getSize().x / backgroundSprite.getGlobalBounds().width,
            window.getSize().y / backgroundSprite.getGlobalBounds().height);
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        player->handleInput(event);
    }
}

void Game::update(sf::Time deltaTime) {
    player->update(deltaTime);

    // Bewege die Plattformen nach unten und aktualisiere den Bildlauf
    float moveDistance = scrollSpeed * deltaTime.asSeconds();
    for (auto& platform : platforms) {
        platform.move(0, moveDistance);
    }
    scrollOffset += moveDistance;

    // Generiere neue Plattformen, wenn nötig
    if (scrollOffset >= platformSpacing) {
        generatePlatform();
        scrollOffset = 0.f;
    }

    // Überprüfe Kollisionen und aktualisiere den Punktestand
    for (auto& platform : platforms) {
        if (player->getBounds().intersects(platform.getBounds()) && player->getBounds().top < platform.getBounds().top) {
            player->setPosition(player->getBounds().left, platform.getBounds().top - player->getBounds().height);
            player->setVelocityY(0);
            player->setJumping(false);  // Spieler ist nicht mehr im Sprung
            score++;
        }
    }

    // Entferne Plattformen, die außerhalb des Bildschirms sind
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(), [](Platform& p) {
        return p.getBounds().top > 600;
    }), platforms.end());
}

void Game::render() {
    window.clear(sf::Color::White);
    window.draw(backgroundSprite);

    for (auto& platform : platforms) {
        platform.draw(window);
    }

    player->draw(window);

    // Zeige den Punktestand an
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Fehlerbehandlung
    }
    sf::Text scoreText("Score: " + std::to_string(score), font, 24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10.f, 10.f);
    window.draw(scoreText);

    window.display();
}

void Game::loadResources() {
    if (!backgroundTexture.loadFromMemory(background_png, background_png_len)) {
        std::cerr << "Failed to load background from memory" << std::endl;
        exit(-1);
    }
    if (!playerTexture.loadFromMemory(player_png, player_png_len)) {
        std::cerr << "Failed to load player from memory" << std::endl;
        exit(-1);
    }
    if (!platformTexture.loadFromMemory(platform_png, platform_png_len)) {
        std::cerr << "Failed to load platform from memory" << std::endl;
        exit(-1);
    }
}

void Game::createPlatforms() {
    for (int i = 0; i < 5; ++i) {
        generatePlatform();
    }
}

void Game::generatePlatform() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> distX(0.f, 800.f - platformTexture.getSize().x);
    float x = distX(rng);
    float y = platforms.empty() ? 500.f : platforms.back().getBounds().top - platformSpacing;
    platforms.push_back(Platform(platformTexture, x, y));
}
