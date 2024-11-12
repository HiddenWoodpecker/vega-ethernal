#pragma once
// #include "Player.hpp"
#include "Sprite.hpp"
class Weapon : public Sprite {

protected:
  unsigned short frame = 0;
  unsigned short framePeriod;
  unsigned short reloadFrame = 0;

public:
  bool isRealoading = false;
  bool isAvailable = false;
  bool isSelected = true;

public:
  Weapon();
  Weapon(Textures txt, Vector2 &position, float offset, float scale,
         int framePeriod);
  virtual void draw(RayCollisionInfo &) = 0;
  virtual void animate(Texture &) = 0;
  virtual void updateFrameCounter(unsigned short) = 0;
  // virtual int getFrame() = 0;
  // virtual void setFrame(unsigned short) = 0;
  // TODO: Weapon logic
  ~Weapon();
};
