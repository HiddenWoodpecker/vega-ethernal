#pragma once
#include "Player.hpp"
#include "Sprite.hpp"
class StaticSprite : public Sprite {
protected:
  bool isVisible = true;

public:
  StaticSprite();
  StaticSprite(Textures txt, Vector2 &position, float offset, float scale);
  virtual void draw(RayCollisionInfo &) = 0;
  virtual bool affectPlayer(Player &) = 0;
  ~StaticSprite();
};
