#pragma once
#include "StaticSprite.hpp"
class AmmoPack : public StaticSprite {
public:
  AmmoPack();
  AmmoPack(Textures txt, Vector2 &position, float offset, float scale);
  void draw(RayCollisionInfo &);
  bool affectPlayer(Player &);
  ~AmmoPack();
};
