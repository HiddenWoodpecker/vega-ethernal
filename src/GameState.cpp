#pragma once
#include "../include/usr/GameState.hpp"
#include "../include/usr/AmmoPack.hpp"
#include "../include/usr/Demon.hpp"
#include "../include/usr/MedPack.hpp"
#include "../include/usr/PathFinder.hpp"
#include "../include/usr/Shotgun.hpp"
#include <iostream>
static std::vector<std::pair<Textures, Vector2>> lvl1Sprites = {
    {Textures::AMMOPACK, (Vector2){500, 500}},
    {Textures::SHOTGUN, (Vector2){0, 0}},
    //{Textures::AMMOPACK, (Vector2){350, 500}},
    {Textures::MEDPACK, (Vector2){350, 400}},
    {Textures::DEMON, (Vector2){400, 750}},
    {Textures::AMMOPACK, (Vector2){400, 400}}};

GameState::GameState()
    : player((Vector2){600, 600}, (Vector2){1.0f, 0.0f}, 5), map(), renderer(),
      rc() {
  loadSprites(lvl1Sprites);
}
std::vector<StaticSprite *> &GameState::getSprites() { return staticSprites; }

std::vector<StaticSprite *> &GameState::getEnemies() { return enemies; }
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
      player.weapons.push_back(ss);
      break;
    }
    if (txt == DEMON) {
      StaticSprite *d = new Demon(pos);

      std::cout << pos.x << " demon " << pos.y << std::endl;
      enemies.push_back(d);
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
  std::vector<RayCollisionInfo> enemiesToDraw = rc.raycastSprites(
      player.getPosition(), player.getViewDirection(), map, this->getEnemies());
  for (int i = 0; i < spritesToDraw.size(); ++i) {
    RayCollisionInfo &rci = spritesToDraw.at(i);

    StaticSprite *ss = dynamic_cast<StaticSprite *>(rci.obj);
    if (ss != nullptr) {
      ss->affectPlayer(player);
    }
  }
  PathFinder pf;
  Vector2 pp = getPlayer().getPosition();
  Vector2 ep = enemies.at(0)->getPosition();
  auto p = pf.findPath(map, pp, ep);
  for (auto &i : p) {
    // DrawRectangle(i.first * WALL_SIZE / 5, i.second * WALL_SIZE / 5,
    //               WALL_SIZE / 5 - 1, WALL_SIZE / 5 - 1, GREEN);
  }
  for (int i = 0; i < enemies.size(); ++i) {

    NPC *ss = dynamic_cast<NPC *>(enemies.at(i));
    DrawCircle(ss->getPosition().x / 5, ss->getPosition().y / 5, 5, GREEN);
    ss->update(player, map, gameCounter);
    // std::cout << 1;
  }
  wallsToDraw.insert(wallsToDraw.end(), spritesToDraw.begin(),
                     spritesToDraw.end());
  wallsToDraw.insert(wallsToDraw.end(), enemiesToDraw.begin(),
                     enemiesToDraw.end());
  renderer.renderObjects(wallsToDraw);
  for (int i = 0; i < player.weapons.size(); ++i) {
    Weapon *wp = player.weapons.at(i);
    wp->isSelected = true;
    wp->updateFrameCounter(GetFrameTime());
    wp->animate(renderer.getTexture(wp->getTexture()));
  }

  ++gameCounter;
}

Player &GameState::getPlayer() { return player; }
void GameState::manageControls() {
  player.manageControls(map);
  if (IsKeyDown(KEY_SPACE)) {
    for (auto &weapon : player.weapons) {
      weapon->isRealoading = true;
    }
  }
}
Renderer &GameState::getRenderer() { return renderer; }

Map &GameState::getMap() { return map; }
