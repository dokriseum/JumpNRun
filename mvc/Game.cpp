#include "Game.h"
#include <iostream>
#include "pic/background.h"
#include "pic/player.h"
#include "pic/platform.h"

Game::Game()
        : window(sf::VideoMode(800, 600), "Jump'n'Run Spiel"), player(nullptr) {
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

    for (auto& platform : platforms) {
        if (player->getBounds().intersects(platform.getBounds()) && player->getBounds().top < platform.getBounds().top) {
            player->setPosition(player->getBounds().left, platform.getBounds().top - player->getBounds().height);
            player->setVelocityY(0);
            player->setJumping(false);  // Spieler ist nicht mehr im Sprung
        }
    }
}

void Game::render() {
    window.clear(sf::Color::White);
    window.draw(backgroundSprite);

    for (auto& platform : platforms) {
        platform.draw(window);
    }

    player->draw(window);
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
    platforms.push_back(Platform(platformTexture, 300.f, 500.f));
    platforms.push_back(Platform(platformTexture, 450.f, 400.f));
    platforms.push_back(Platform(platformTexture, 200.f, 300.f));
    platforms.push_back(Platform(platformTexture, 600.f, 200.f));
}
