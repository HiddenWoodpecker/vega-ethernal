#pragma once
#include "../include/usr/GameState.hpp"
#include "../include/usr/AmmoPack.hpp"
#include "../include/usr/MedPack.hpp"
#include "../include/usr/Shotgun.hpp"
#include <iostream>
static std::vector<std::pair<Textures, Vector2>> lvl1Sprites = {
    {Textures::AMMOPACK, (Vector2){500, 500}},
    {Textures::SHOTGUN, (Vector2){0, 0}},
    //{Textures::AMMOPACK, (Vector2){350, 500}},
    {Textures::MEDPACK, (Vector2){350, 400}},
    {Textures::AMMOPACK, (Vector2){400, 400}}};

GameState::GameState()
    : player((Vector2){600, 600}, (Vector2){1.0f, 0.0f}, 5), map(), renderer(),
      rc() {
  loadSprites(lvl1Sprites);
}
std::vector<StaticSprite *> &GameState::getSprites() { return staticSprites; }

void GameState::loadSprites(
    std::vector<std::pair<Textures, Vector2>> &sprites) {
  for (const auto &pair : sprites) {
    Textures txt = pair.first;
    Vector2 pos = pair.second;
    StaticSprite *ss;
    switch (txt) {
    case MEDPACK:
      std::cout << pos.x << " med pos " << pos.y << std::endl;
      ss = new MedPack(txt, pos, 1.0f, 0.2f);
      staticSprites.push_back(ss);
      break;
    case AMMOPACK:
      std::cout << pos.x << " POSTION " << pos.y << std::endl;
      ss = new AmmoPack(txt, pos, 1.5f, 1.0f);
      staticSprites.push_back(ss);
      break;

    case SHOTGUN:
      std::cout << pos.x << " shotgn " << pos.y << std::endl;
      Weapon *ss = new Shotgun(txt, pos, 1.5f, 3.0f, 2);
      weapons.push_back(ss);
      break;
    }
  }
}

Raycaster &GameState::getRaycaster() { return rc; }
void GameState::update() {

  manageControls();
  // Отрисовка текстур
  std::vector<RayCollisionInfo> wallsToDraw =
      rc.raycast(player.getPosition(), player.getViewDirection(), map);
  std::vector<RayCollisionInfo> spritesToDraw = rc.raycastSprites(
      player.getPosition(), player.getViewDirection(), map, this->getSprites());
  for (int i = 0; i < spritesToDraw.size(); ++i) {
    RayCollisionInfo &rci = spritesToDraw.at(i);

    StaticSprite *ss = dynamic_cast<StaticSprite *>(rci.obj);
    if (ss != nullptr) {
      ss->affectPlayer(player);
    }
  }
  wallsToDraw.insert(wallsToDraw.end(), spritesToDraw.begin(),
                     spritesToDraw.end());
  renderer.renderObjects(wallsToDraw);
  for (int i = 0; i < weapons.size(); ++i) {

    Weapon *wp = weapons.at(i);
    wp->isSelected = true;
    wp->updateFrameCounter(gameCounter);
    wp->animate(renderer.getTexture(wp->getTexture()));
  }

  ++gameCounter;
}

Player &GameState::getPlayer() { return player; }
void GameState::manageControls() {
  player.manageControls(map);
  if (IsKeyDown(KEY_SPACE)) {
    for (auto &weapon : weapons) {
      weapon->isRealoading = true;
    }
  }
}
Renderer &GameState::getRenderer() { return renderer; }

Map &GameState::getMap() { return map; }
