#include "../include/usr/PathFinder.hpp"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
bool PathFinder::isVisited(vector<pair<cell, cell>> &visited, cell current) {
  for (auto a : visited) {
    if (a.second == current) {
      return true;
    }
  }
  return false;
}
cell PathFinder::findCell(vector<pair<cell, cell>> &visited, cell current) {
  for (auto a : visited) {
    if (a.first == current) {
      return a.second;
    }
  }
  return make_pair(-1, -1);
}

vector<cell> PathFinder::findPath(Map &map, Vector2 &player, Vector2 &npc) {
  // cout << "AAAAAAAAAAAAAAa";
  queue<cell> toVisit;
  vector<pair<cell, cell>> visited;
  cell start = make_pair((int)((float)npc.x / WALL_SIZE),
                         (int)((float)npc.y / WALL_SIZE));
  cell finish =
      make_pair((float)player.x / WALL_SIZE, (float)player.y / WALL_SIZE);
  // cout << start.first << " " << start.second << endl;
  // cout << finish.first << " " << finish.second << endl;
  cell current;
  visited.push_back(make_pair(start, make_pair(-1, -1)));

  // cout << "pp" << player.x << " " << player.y << endl;
  // cout << "ep" << npc.x << " " << npc.y << endl;
  toVisit.push(start);
  while (!toVisit.empty()) {

    current = toVisit.front();
    // cout << "front" << toVisit.front().first << " " << toVisit.front().second
    //      << endl;
    // cout << "tovisit sizxe" << toVisit.size();
    toVisit.pop();
    // cout << "cureretn" << current.first << " " << current.second << endl;
    // cout << "finsih" << finish.first << " " << finish.second << endl;
    if (toVisit.size() > 152) {
      vector<cell> nopath;
      nopath.push_back(make_pair(-1, -1));
      return nopath;
    }
    if (current == finish) {

      // cout << "break" << current.first << " " << current.second << endl;
      break;
    }
    // cout << "visited:" << endl;
    // for (auto p : visited) {
    //   cout << p.first.first << ' ' << p.first.second << endl;
    // }
    // cout << "visited!" << endl;
    if (!isVisited(visited, current)) {
      cell up = make_pair(current.first, current.second + 1);
      cell down = make_pair(current.first, current.second - 1);
      cell left = make_pair(current.first - 1, current.second);
      cell right = make_pair(current.first + 1, current.second);
      // cout << "UP PAIR" << up.first << " "<<up.second << endl;
      // cout << "down PAIR" << down.first << " "<<down.second << endl;
      // cout << "left PAIR" << left.first << " "<<left.second << endl;
      // cout << "right PAIR" << right.first << " "<<right.second << endl;

      if (!isVisited(visited, up) && map.isCellPassable(up.first, up.second)) {
        toVisit.push(up);
        visited.push_back(make_pair(up, current));
      }
      if (!isVisited(visited, down) &&
          map.isCellPassable(down.first, down.second)) {
        toVisit.push(down);
        visited.push_back(make_pair(down, current));
      }
      if (!isVisited(visited, right) &&
          map.isCellPassable(right.first, right.second)) {
        toVisit.push(right);
        visited.push_back(make_pair(right, current));
      }
      if (!isVisited(visited, left) &&
          map.isCellPassable(left.first, left.second)) {
        toVisit.push(left);
        visited.push_back(make_pair(left, current));
      }
    }
  }

  vector<cell> path;
  while (finish != start) {
    path.push_back(finish);

    finish = findCell(visited, finish);
    if (finish == make_pair(-1, -1)) {
      break;
    }
  }
  return path;
}
