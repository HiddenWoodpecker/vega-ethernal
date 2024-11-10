#pragma once
#include "Object.hpp"
class Sprite : public Object {
protected:
  int height;
  int width;

public:
  Sprite();
  Sprite(Textures txt, Vector2 &position, int width, int height);
  void setSize(Vector2);
  Vector2 getSize() const;
  virtual void draw(RayCollisionInfo &) = 0;
  ~Sprite();
};
