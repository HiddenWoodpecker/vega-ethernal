#pragma once
#include "Wall.hpp"
class Map {
private:
  static const short mapHeight = 17;
  static const short mapWidth = 10;
  Wall *mapContent[mapHeight][mapWidth];

public:
  void update();
  void draw();
  bool isCellPassable(int x, int y) {
    if (x < 0 || y < 0 || x >= mapHeight || y >= mapWidth) {
      return false;
    }
    if (at((float)x, (float)(y)) != nullptr) {
      return false;
    }
    return true;
  }
  Map();
  Wall *at(float, float);
  ~Map();
  //    Object createObject();
  //
  //    Object deleteObject();
  friend void fillMap(Map &map);
};
