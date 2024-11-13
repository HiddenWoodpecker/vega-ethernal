#pragma once
#include "Map.hpp"
#include <utility>

#define cell pair<int, int>
using namespace std;
class PathFinder {
public:
  PathFinder() {};
  ~PathFinder() {};
  bool isVisited(vector<pair<cell, cell>> &visited, cell current);
  cell findCell(vector<pair<cell, cell>> &visited, cell current);
  vector<cell> findPath(Map &map, Vector2 &player, Vector2 &npc);
};
