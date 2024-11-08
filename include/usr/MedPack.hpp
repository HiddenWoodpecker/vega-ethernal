#pragma once
#include "StaticSprite.hpp"
class MedPack : public StaticSprite {
public:
  MedPack();
  MedPack(Textures txt, Vector2 &position);
  void draw(RayCollisionInfo &);
  void affectPlayer(Player &);
  ~MedPack();
};
