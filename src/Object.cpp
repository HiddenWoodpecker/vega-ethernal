#include "../include/usr/Object.hpp"
#include <cstring>
Object::Object(){};
Object::Object(Vector2 &position) : position(position){};
Object::Object(Vector2 &position, Textures txt)
    : position(position), texture(txt){};
Textures Object::getTexture() const { return texture; }
Vector2 Object::getPosition() const { return position; }
//  void Object::draw() {};
std::string Object::to_String() {
  std::string str = "obj at adress";
  str.append((char *)(this));
  return str;
}
Object::~Object(){};
