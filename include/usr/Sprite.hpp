#pragma once
#include "Object.hpp"
class Sprite : public Object {
protected:
  int height;
  int width;

public:
  Sprite();
  Sprite(Textures txt, Vector2 &position);
  virtual void draw(RayCollisionInfo &) = 0;
  ~Sprite();
};
