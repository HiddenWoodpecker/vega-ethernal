#pragma once
#include "../Texture.hpp"
#include "../Vector2.hpp"
#include "Settings.hpp"
#include <string>
class Object;
struct RayCollisionInfo {
  Object *obj;
  Texture *txt;
  bool isWallHit;
  bool isStaticObjectHit;
  bool isNPCHit;
  float distance;
  float offset;
  Vector2 hitPoint;
  int rayNum;
  float projectionHeight;
  RayCollisionInfo() : txt(nullptr), obj(nullptr){};
};
class Object {
protected:
  Vector2 position;
  Textures texture;

public:
  Object();
  Object(Vector2 &);
  Object(Vector2 &, Textures);
  virtual Textures getTexture();
  virtual void draw(RayCollisionInfo &) = 0;
  //  virtual void move(Vector2);
  virtual std::string to_String();
  virtual ~Object();
};
