#pragma once
#include "Sprite.hpp"
class NPC : public Sprite {
protected:
public:
  NPC();
  NPC(Textures txt, Vector2 &position);
  virtual void draw(RayCollisionInfo &) = 0;
  // TODO: NPC logic
  ~NPC();
};
