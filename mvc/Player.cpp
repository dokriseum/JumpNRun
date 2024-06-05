#include "Player.h"

Player::Player(const sf::Texture& texture)
        : movingLeft(false), movingRight(false), jumping(false) {
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);  // Passe die Größe des Spielers an
}

void Player::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            movingLeft = true;
        }
        if (event.key.code == sf::Keyboard::Right) {
            movingRight = true;
        }
        if (event.key.code == sf::Keyboard::Space) {
            if (!jumping) {
                velocity.y = jumpPower;
                jumping = true;
            }
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left) {
            movingLeft = false;
        }
        if (event.key.code == sf::Keyboard::Right) {
            movingRight = false;
        }
    }
}

void Player::update() {
    if (movingLeft) {
        sprite.move(-playerSpeed, 0);
    }
    if (movingRight) {
        sprite.move(playerSpeed, 0);
    }

    velocity.y += gravity;
    sprite.move(0, velocity.y);

    if (sprite.getPosition().x < 0) {
        sprite.setPosition(0, sprite.getPosition().y);
    }
    if (sprite.getPosition().x > 800 - sprite.getGlobalBounds().width) {
        sprite.setPosition(800 - sprite.getGlobalBounds().width, sprite.getPosition().y);
    }
    if (sprite.getPosition().y > 600 - sprite.getGlobalBounds().height) {
        sprite.setPosition(sprite.getPosition().x, 600 - sprite.getGlobalBounds().height);
        velocity.y = 0;
        jumping = false;
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Player::setVelocityY(float vy) {
    velocity.y = vy;
}

bool Player::isJumping() const {
    return jumping;
}

void Player::setJumping(bool jump) {
    jumping = jump;
}
