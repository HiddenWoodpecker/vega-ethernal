#include "Map.hpp"
class Player {
private:
  float fov;
  Vector2 viewDirection;
  float moveSpeed;
  Vector2 position;

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
