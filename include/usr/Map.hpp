#pragma once
#include "Wall.hpp"
class Map {
private:
  static const short mapHeight = 10;
  static const short mapWidth = 10;
  Wall *mapContent[mapHeight][mapWidth];

public:
  void update();
  void draw();
  Map();
  Wall *at(float, float);
  ~Map();
  //    Object createObject();
  //    Object deleteObject();
  friend void fillMap(Map &map);
};
