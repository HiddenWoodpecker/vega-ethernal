#pragma once
#include "Map.hpp"
#include "Object.hpp"
#include "StaticSprite.hpp"
#include <unordered_map>
#include <utility>
#include <vector>

enum NPCSTATE {
  RUNNING,
  ATTACK,
  HURT,
  IDLE,
  DEATH,
};

class NPC : StaticSprite {
protected:
  // Vector2 position;
  std::unordered_map<NPCSTATE, std::vector<Texture>> textures;
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
  virtual void update(Player &, Map &);
  virtual void runLogic(Player &, Map &);
  virtual void draw(RayCollisionInfo &);
  virtual void changeState();
  virtual bool affectPlayer(Player &);
};

class Demon : NPC {

public:
  Demon();
  Demon(Vector2 &);
  ~Demon();
  void update(Player &, Map &);
  void runLogic(Player &, Map &);
  void draw(RayCollisionInfo &);
  void changeState();
  bool affectPlayer(Player &);
};
