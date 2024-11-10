#pragma once
#include "Player.hpp"
#include "Sprite.hpp"
class StaticSprite : public Sprite {
public:
  StaticSprite();
  StaticSprite(Textures txt, Vector2 &position, int width, int height);
  virtual void draw(RayCollisionInfo &) = 0;
  virtual void affectPlayer(Player &) = 0;
  ~StaticSprite();
};
