#include "../include/usr/GameState.hpp"
#include "../include/usr/AmmoPack.hpp"
#include <iostream>
static std::vector<std::pair<Textures, Vector2>> lvl1Sprites = {
    {Textures::AMMOPACK, (Vector2){500, 500}},
    {Textures::AMMOPACK, (Vector2){350, 500}},
    {Textures::AMMOPACK, (Vector2){400, 400}}};

GameState::GameState()
    : player((Vector2){500, 500}, (Vector2){1.0f, 0.0f}, 5), map(), renderer() {
  loadSprites(lvl1Sprites);
}
std::vector<StaticSprite *> &GameState::getSprites() { return staticSprites; }

void GameState::loadSprites(
    std::vector<std::pair<Textures, Vector2>> &sprites) {
  for (const auto &pair : sprites) {
    Textures txt = pair.first;
    Vector2 pos = pair.second;
    switch (txt) {
    case AMMOPACK:
      std::cout << pos.x << " POSTION " << pos.y << std::endl;
      StaticSprite *ss = new AmmoPack(txt, pos, 126, 126);
      staticSprites.push_back(ss);
    }
  }
}

Player &GameState::getPlayer() { return player; }

Renderer &GameState::getRenderer() { return renderer; }

Map &GameState::getMap() { return map; }
