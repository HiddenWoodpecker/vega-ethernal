#pragma once
#include "Map.hpp"
#include "Object.hpp"
#include "StaticSprite.hpp"
#include <unordered_map>
#include <utility>
#include <vector>

enum NPCSTATE {
  WALK,
  ATTACK,
  PAIN,
  IDLE,
  DEATH,
};

class NPC : StaticSprite {
protected:
  // Vector2 position;
  unsigned short frameCounter = 0;
  unsigned short framePeriod = 30;
  NPCSTATE state = IDLE;
  float speed = 2.0f;
  int sizeScale = 1;
  int damage = 10;
  int health = 100;
  bool isAlive = true;
  bool isAggresive = false;

public:
  NPC();
  NPC(Vector2 &);
  ~NPC();
  virtual void update(Player &, Map &) = 0;
  virtual void runLogic(Player &, Map &) = 0;
  virtual void draw(RayCollisionInfo &) = 0;
  virtual void changeState() = 0;
  virtual bool affectPlayer(Player &) = 0;
};
