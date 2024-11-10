#include "../include/usr/Sprite.hpp"

Sprite::Sprite() : Object(){};
Sprite::Sprite(Textures txt, Vector2 &position, int width, int height)
    : Object(position, txt), width(width), height(height){};
Vector2 Sprite::getSize() const {
  return (Vector2){(float)width, (float)height};
}

void Sprite::setSize(Vector2 newSize) {
  width = newSize.x;
  height = newSize.y;
}
Sprite::~Sprite(){};
