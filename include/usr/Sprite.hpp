#pragma once
#include "Object.hpp"
class Sprite : public Object {
protected:
  float offset;
  float scale;

public:
  Sprite();
  Sprite(Textures txt, Vector2 &position, float offset, float scale);
  // void setSize(Vector2);
  // Vector2 getSize() const;
  virtual void draw(RayCollisionInfo &) = 0;
  ~Sprite();
};
