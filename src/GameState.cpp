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
    {Textures::MEDPACK, (Vector2){350, 450}},
    {Textures::DEMON, (Vector2){400, 750}},
    {Textures::DEMON, (Vector2){600, 950}},
    {Textures::DEMON, (Vector2){500, 550}},
    {Textures::DEMON, (Vector2){1200, 600}},
    {Textures::DEMON, (Vector2){1100, 550}},
    {Textures::DEMON, (Vector2){1200, 550}},
    {Textures::MEDPACK, (Vector2){1000, 550}},
    {Textures::AMMOPACK, (Vector2){250, 1900}},
    {Textures::DEMON, (Vector2){250, 1900}},
    {Textures::AMMOPACK, (Vector2){1200, 600}},
    {Textures::DEMON, (Vector2){WALL_SIZE * 10, WALL_SIZE * 2 + 50}},
    {Textures::DEMON, (Vector2){WALL_SIZE * 10, WALL_SIZE * 2}},
    {Textures::AMMOPACK, (Vector2){450, 450}}};

GameState::GameState()
    : player((Vector2){2000, 670}, (Vector2){1.0f, 0.0f}, 5), map(), renderer(),
      rc() {
  loadSprites(lvl1Sprites);
  SetRandomSeed(5);
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
      ss = new AmmoPack(txt, pos, 1.0f, 1.0f);
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
  if (player.health < 0) {
    ClearBackground(BLACK);
    DrawText("GAME OVER", WINDOW_WIDTH / 2 - 100, WINDOWN_HALF_HEIGHT, 32, RED);
  } else {
    manageControls();
    // cout << player.getPosition().x << ' ' << player.getPosition().y << endl;

    std::vector<RayCollisionInfo> objectsToRender =
        rc.raycast(player.getPosition(), player.getViewDirection(), map);
    std::vector<RayCollisionInfo> spritesToDraw =
        rc.raycastSprites(player.getPosition(), player.getViewDirection(), map,
                          this->getSprites());
    std::vector<RayCollisionInfo> enemiesToDraw =
        rc.raycastSprites(player.getPosition(), player.getViewDirection(), map,
                          this->getEnemies());

    for (int i = 0; i < spritesToDraw.size(); ++i) {
      RayCollisionInfo &rci = spritesToDraw.at(i);

      StaticSprite *ss = dynamic_cast<StaticSprite *>(rci.obj);
      ss->affectPlayer(player);
    }

    objectsToRender.insert(objectsToRender.end(), spritesToDraw.begin(),
                           spritesToDraw.end());
    objectsToRender.insert(objectsToRender.end(), enemiesToDraw.begin(),
                           enemiesToDraw.end());
    renderer.renderObjects(objectsToRender);

    // ОТрисовка оружия
    for (int i = 0; i < player.weapons.size(); ++i) {
      Weapon *wp = player.weapons.at(i);
      wp->isSelected = true;
      wp->updateFrameCounter(GetFrameTime());
      wp->animate(renderer.getTexture(wp->getTexture()));
      if (wp->isSelected) {
        DrawText(TextFormat("AMMO: [%i]", wp->ammo), WINDOW_WIDTH - 200, 72, 20,
                 GREEN);
      }
    }

    ++gameCounter;
    if (gameCounter % 100 == 0) {

      cout << player.health << endl;
    }
    for (int i = 0; i < enemies.size(); ++i) {

      NPC *ss = dynamic_cast<NPC *>(enemies.at(i));
      if (ss != nullptr) {
        if (ss->isVisible) {
          ss->update(player, map, gameCounter);
          // Отрисовка врагов на миникарте
          DrawCircle(ss->getPosition().x / 5, ss->getPosition().y / 5, 5,
                     GREEN);
        }
      }
    }
    // Отрисовка игрока на миникарте
    DrawCircle(player.getPosition().x / 5, player.getPosition().y / 5, 5, BLUE);
    // Отрисовка стрен на миникарте
    map.draw();

    // Здоровье игрока
    DrawText(TextFormat("HEALTH: [%i]", player.health), WINDOW_WIDTH - 200, 50,
             20, GREEN);
  }
}

Player &GameState::getPlayer() { return player; }
void GameState::manageControls() {
  player.manageControls(map);
  if (IsKeyDown(KEY_SPACE)) {
    for (auto &weapon : player.weapons) {
      if (weapon->isSelected) {
        if (!weapon->isRealoading && weapon->ammo > 0) {

          weapon->ammo -= 1;
          weapon->isRealoading = true;
          for (auto enemy : enemies) {
            NPC *ss = dynamic_cast<NPC *>(enemy);
            if (ss != nullptr) {
              ss->getDamage(player, map, weapon->damage);
            }
          }
        }
      }
    }
  }
}
Renderer &GameState::getRenderer() { return renderer; }

Map &GameState::getMap() { return map; }
