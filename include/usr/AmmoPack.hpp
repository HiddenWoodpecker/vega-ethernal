#pragma once
#include "StaticSprite.hpp"
class AmmoPack : public StaticSprite {
public:
  AmmoPack();
  AmmoPack(Textures txt, Vector2 &position);
  void draw(RayCollisionInfo &);
  void affectPlayer(Player &);
  ~AmmoPack();
};
