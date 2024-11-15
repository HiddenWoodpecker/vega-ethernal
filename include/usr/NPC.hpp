#pragma once
#include "Map.hpp"
#include "Object.hpp"
#include "Settings.hpp"
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

class NPC : public StaticSprite {
protected:
  unsigned short frameCounter = 0;
  unsigned short framePeriod = 120;
  // unsigned short painCounter;
  unsigned short painFrame = 0;
  // unsigned short deathCounter = 5000;
  unsigned short deathFrame = 0;
  bool triggerAnimation = false;

  NPCSTATE state = IDLE;
  float speed = 1.5f;
  float scale = 1.0f;
  float offset = 0.1f;
  int damage = 20;
  int health = 100;
  int attackRange = WALL_SIZE * 5;
  bool isAlive = true;
  bool isAggresive = false;
  int size = 50;

public:
  NPC();
  NPC(Vector2 &);
  ~NPC();
  virtual void update(Player &, Map &, int) = 0;
  virtual void getDamage(Player &, Map &, int) = 0;
  virtual void runLogic(Player &, Map &, int) = 0;
  virtual void draw(RayCollisionInfo &) = 0;
  virtual void changeState(NPCSTATE) = 0;
  virtual bool affectPlayer(Player &) = 0;
};
