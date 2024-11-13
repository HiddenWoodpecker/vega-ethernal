#include "Map.hpp"
#include "Weapon.hpp"
class Player {
private:
  float fov;
  Vector2 viewDirection;
  float moveSpeed;
  Vector2 position;
  int health;

public:
  std::vector<Weapon *> weapons;

public:
  Player(Vector2 initPos, Vector2 viewDirection, float moveSpeed);
  void move(Vector2 direction, Map &map);
  void manageControls(Map &map);
  // void draw() override;
  void rotateCamera(float angle);
  Vector2 getViewDirection();
  Vector2 getPosition();
  ~Player();
};
