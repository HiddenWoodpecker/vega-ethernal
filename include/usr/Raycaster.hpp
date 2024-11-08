#pragma once
#include "Map.hpp"
#include "Object.hpp"
#ifndef TEXTURES_
#define TEXTURES_
enum Textures {
  BRICK_WALL,
  DO_NOT_LOAD,
  BRICK_WALL2,
};
#endif

class Raycaster {
  // raycast ---> find first wall entity that ray hits ---> draw that wall
public:
  Raycaster();

  std::vector<RayCollisionInfo> raycast(Vector2 initPos, Vector2 viewDirection,
                                        Map &map);
  RayCollisionInfo castSingleRay(Vector2 &initPos, Vector2 &viewDirection,
                                 Map &map, Vector2 &initialViewDirection);
  ~Raycaster();
};
