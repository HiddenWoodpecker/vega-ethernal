#include "../include/usr/Map.hpp"
#include "../include/usr/Settings.hpp"
static int map1[17][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 2, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 3, 3, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {3, 1, 0, 0, 0, 0, 0, 0, 1, 3}, {3, 1, 0, 0, 0, 0, 0, 0, 2, 3},
    {1, 1, 0, 1, 0, 0, 0, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 3, 3, 3, 3, 1, 1, 1, 2}};

void fillMap(Map &map) {

  for (int i = 0; i < Map::mapHeight; ++i) {
    for (int j = 0; j < Map::mapWidth; ++j) {
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
  for (int i = 0; i < Map::mapHeight; ++i) {
    for (int j = 0; j < Map::mapWidth; ++j) {
      if (mapContent[i][j] != nullptr) {
        DrawRectangle(i * WALL_SIZE / 5, j * WALL_SIZE / 5, WALL_SIZE / 5,
                      WALL_SIZE / 5, RED);
      }
    }
  }
}

Map::Map() { fillMap(*this); };

Map::~Map() {}
