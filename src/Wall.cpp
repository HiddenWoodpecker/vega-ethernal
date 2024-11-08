#include "../include/usr/Wall.hpp"
#include "../include/usr/Settings.hpp"

#include "../include/usr/Renderer.hpp"

Wall::Wall(){};

Wall::Wall(Textures txt, Vector2 &position) : Object(position, txt) {}

void Wall::draw(RayCollisionInfo &rci) {

  Rectangle r = Rectangle{(int)(WALL_SIZE - HORIZONTAL_RESOLUTION) * rci.offset,
                          0, (int)HORIZONTAL_RESOLUTION, WALL_HEIGHT};

  Rectangle dest = {(float)HORIZONTAL_RESOLUTION * rci.rayNum,
                    (float)WINDOWN_HALF_HEIGHT -
                        (float)rci.projectionHeight / 2,
                    (float)HORIZONTAL_RESOLUTION, (float)rci.projectionHeight};
  DrawTexturePro(*(rci.txt), r, dest, (Vector2){0, 0}, 0.0f, WHITE);
}

Wall::~Wall(){};
