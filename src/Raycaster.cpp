#include "../include/usr/Raycaster.hpp"
#include <iostream>
#include <vector>

Raycaster::Raycaster(){};

inline short signum(double x) {
  if (x == (double)0) {
    return 0;
  }
  if (x > 0) {
    return 1;
  }
  return -1;
}

std::vector<RayCollisionInfo>
Raycaster::raycast(Vector2 initPos, Vector2 viewDirection, Map &map) {
  double posX, posY, cos_alfa, sin_alfa, tan_alfa, verticalHitDistance,
      horizontalHitDistance;
  int mapPosX, mapPosY;
  std::vector<RayCollisionInfo> wallsToDraw;
  wallsToDraw.resize(NUM_RAYS);
  posX = initPos.x;
  posY = initPos.y;

  mapPosX = static_cast<int>(initPos.x / WALL_SIZE);
  mapPosY = static_cast<int>(initPos.y / WALL_SIZE);
  Vector2 initialVievDirection = Vector2(viewDirection);
  viewDirection = Vector2Rotate(viewDirection, -DEFAULT_HALF_FOV);
  for (int rayNum = 0; rayNum < NUM_RAYS; ++rayNum) {
    double alfa = Vector2Angle((Vector2){1, 0}, viewDirection);
    cos_alfa = cos(alfa);
    sin_alfa = sin(alfa);
    tan_alfa = tan(alfa);
    RayCollisionInfo rciVer, rciHor;
    // verical hit
    double dx = cos_alfa >= 0 ? ((WALL_SIZE - (int)posX % WALL_SIZE))
                              : (-(int)posX % WALL_SIZE);
    double dy = dx * tan_alfa;
    int depth_counter = 0;
    double ver_dist = abs(dx / abs(cos_alfa));
    double ver_dist_delta = WALL_SIZE / abs(cos_alfa);
    double rayMapPosX = cos_alfa > 0 ? mapPosX + 1 : mapPosX - EPS;
    double rayMapPosY = (posY + dy + EPS * signum(sin_alfa)) / WALL_SIZE;
    while (map.at(rayMapPosX, rayMapPosY) == nullptr &&
           depth_counter < RAYCAST_MAX_RANGE) {
      dx += cos_alfa > 0 ? WALL_SIZE : -WALL_SIZE;
      dy = dx * tan_alfa;
      rayMapPosX += cos_alfa > 0 ? 1 : -1;
      ver_dist += ver_dist_delta;
      rayMapPosY = (posY + dy + EPS * signum(sin_alfa)) / WALL_SIZE;
      ++depth_counter;
    }

    rciVer.obj = map.at(rayMapPosX, rayMapPosY);
    rciVer.distance = ver_dist;
    rciVer.offset = cos_alfa > 0 ? rayMapPosY - (int)rayMapPosY
                                 : 1 - (rayMapPosY - (int)rayMapPosY);
    rciVer.isWallHit = depth_counter == RAYCAST_MAX_RANGE ? false : true;
    rciVer.hitPoint = Vector2Add(initPos, (Vector2){(float)dx, (float)dy});

    // horizontal hit
    dy = sin_alfa >= 0 ? ((WALL_SIZE - (int)posY % WALL_SIZE))
                       : (-(int)posY % WALL_SIZE);
    dx = dy / tan_alfa;
    depth_counter = 0;
    double hor_dist = abs(dy / abs(sin_alfa));
    double hor_dist_delta = WALL_SIZE / abs(sin_alfa);
    rayMapPosY = sin_alfa > 0 ? mapPosY + 1 : mapPosY - EPS;
    rayMapPosX = (posX + dx + EPS * signum(cos_alfa)) / WALL_SIZE;
    // RayCollisionInfo rc;
    while (map.at(rayMapPosX, rayMapPosY) == nullptr &&
           depth_counter < RAYCAST_MAX_RANGE) {
      dy += sin_alfa > 0 ? WALL_SIZE : -WALL_SIZE;
      dx = dy / tan_alfa;
      rayMapPosY += sin_alfa > 0 ? 1 : -1;
      hor_dist += hor_dist_delta;
      rayMapPosX = ((posX + dx + EPS * signum(cos_alfa)) / WALL_SIZE);
      ++depth_counter;
    }
    rciHor.obj = map.at(rayMapPosX, rayMapPosY);
    rciHor.distance = hor_dist;
    rciHor.offset = sin_alfa > 0 ? 1 - (rayMapPosX - (int)rayMapPosX)
                                 : (rayMapPosX - (int)rayMapPosX);

    rciHor.isWallHit = depth_counter == RAYCAST_MAX_RANGE ? false : true;
    rciHor.hitPoint = Vector2Add(initPos, (Vector2){(float)dx, (float)dy});

    if (rciVer.distance < rciHor.distance) {
      // DrawLineEx(initPos, rciVer.hitPoint, 1, raylib::Color(BLUE));
      rciVer.projectionHeight =
          (float)SCREEN_DIST * WALL_HEIGHT / (rciVer.distance + EPSILON) /
          cos(Vector2Angle(viewDirection, initialVievDirection));

      rciVer.rayNum = rayNum;
      wallsToDraw.push_back(rciVer);
    } else {
      rciHor.projectionHeight =
          (float)SCREEN_DIST * WALL_HEIGHT / (rciHor.distance + EPSILON) /
          cos(Vector2Angle(viewDirection, initialVievDirection));

      rciHor.rayNum = rayNum;
      wallsToDraw.push_back(rciHor);
    }
    // TODO: draw part of image with ImageCrop
    viewDirection = Vector2Rotate(viewDirection, DELTA_ANGLE);
  }
  return wallsToDraw;
}

Raycaster::~Raycaster(){};
