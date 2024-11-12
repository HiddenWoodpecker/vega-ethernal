#pragma once
#include "StaticSprite.hpp"
class MedPack : public StaticSprite {
public:
  MedPack();
  MedPack(Textures txt, Vector2 &position, float, float);
  void draw(RayCollisionInfo &);
  bool affectPlayer(Player &);
  ~MedPack();
};
