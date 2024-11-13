#include "../include/usr/Map.hpp"
#include "../include/usr/Settings.hpp"
static int map1[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 2}, {2, 0, 0, 0, 0, 0, 0, 0, 2, 2},
    {1, 1, 3, 3, 3, 3, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void fillMap(Map &map) {

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (map1[i][j] != 0) {
        Vector2 wallPosition = {(float)i, (float)j};
        map.mapContent[i][j] =
            new Wall((Textures)(map1[i][j] - 1), wallPosition);
      } else {
        map.mapContent[i][j] = nullptr;
      }
    }
  }
}

Wall *Map::at(float i, float j) {
  int x, y;
  x = (int)i;
  y = (int)j;
  if (i < mapHeight && j < mapWidth && i >= 0 && j >= 0) {
    return mapContent[x][y];
  }
  return nullptr;
}

void Map::draw() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (mapContent[i][j] != nullptr) {
        //(mapContent[i][j])->draw();
      }
    }
  }
}

Map::Map() { fillMap(*this); };

Map::~Map() {}
