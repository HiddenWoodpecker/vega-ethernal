#pragma once
#include "Object.hpp"
class Wall : public Object {
public:
  Wall();
  Wall(Textures txt, Vector2 &position);
  void draw(RayCollisionInfo &) override;
  ~Wall();
};
