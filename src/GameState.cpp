#include "../include/usr/GameState.hpp"

GameState::GameState()
    : player((Vector2){500, 500}, (Vector2){1.0f, 0.0f}, 5), map(), renderer() {
}

Player &GameState::getPlayer() { return player; }

Renderer &GameState::getRenderer() { return renderer; }

Map &GameState::getMap() { return map; }
