#pragma once
// #include "Object.hpp"
// #include "Player.hpp"
#include "Raycaster.hpp"
#include "Renderer.hpp"
#include "Settings.hpp"
#include "StaticSprite.hpp"
#include "Weapon.hpp"
class GameState {
private:
  Player player;
  Map map;
  Renderer renderer;
  Raycaster rc;
  unsigned short gameCounter;
  std::vector<Object *> enemies;
  std::vector<StaticSprite *> staticSprites;
  std::vector<Weapon *> weapons;
  // std::vector<Projectiles>
public:
  GameState();
  // void applyEffectToPlayer();
  void loadSprites(std::vector<std::pair<Textures, Vector2>> &sprites);
  std::vector<StaticSprite *> &getSprites();
  Renderer &getRenderer();
  Player &getPlayer();
  Map &getMap();
  Raycaster &getRaycaster();
  void update();
  void manageControls();
  ~GameState() {
    for (auto a : staticSprites) {
      delete a;
    }
    for (auto a : enemies) {
      delete a;
    }
  }
};
