#pragma once
#include "Object.hpp"
#include "Player.hpp"
// #include "Raycaster.hpp"
#include "Renderer.hpp"
class GameState {
private:
  Player player;
  Map map;
  Renderer renderer;
  std::vector<Object *> enemies;
  // std::vector<Projectiles>
public:
  GameState();
  Renderer &getRenderer();
  Player &getPlayer();
  Map &getMap();
};
