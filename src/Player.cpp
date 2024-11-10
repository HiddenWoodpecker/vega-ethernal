#include "../include/usr/Player.hpp"
#include "../include/raylib.hpp"

Player::Player(Vector2 initPos, Vector2 viewDirection, float moveSpeed)
    : position(initPos), viewDirection(viewDirection), moveSpeed(moveSpeed){};

void Player::move(Vector2 dir, Map &map) {
  float dx = dir.x * moveSpeed;
  float dy = dir.y * moveSpeed;
  if (map.at((position.x + dx) / WALL_SIZE, (position.y + dy) / WALL_SIZE) ==
      nullptr) {
    position.x += dx;
    position.y += dy;
  }
  // TODO :: COLLISIONS
}

void Player::manageControls(Map &map) {
  if (IsKeyDown(KEY_W)) {
    this->move(this->getViewDirection(), map);
  }
  if (IsKeyDown(KEY_A)) {
    this->move(Vector2Rotate(this->getViewDirection(), -PI / 2), map);
  }
  if (IsKeyDown(KEY_D)) {
    this->move(Vector2Rotate(this->getViewDirection(), PI / 2), map);
  }
  if (IsKeyDown(KEY_S)) {
    this->move(Vector2Scale(this->getViewDirection(), -1.0f), map);
  }
  if (IsKeyDown(KEY_RIGHT)) {
    this->rotateCamera(PI / 60);
  }
  if (IsKeyDown(KEY_LEFT)) {
    this->rotateCamera(-PI / 60);
  }
}
void Player::rotateCamera(float angle) {
  viewDirection = Vector2Rotate(viewDirection, angle);
}

Vector2 Player::getViewDirection() { return viewDirection; }

Vector2 Player::getPosition() { return position; }

Player::~Player(){};
