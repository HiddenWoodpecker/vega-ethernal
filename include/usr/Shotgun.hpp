#pragma once
#include "Weapon.hpp"

class Shotgun : public Weapon {

  // protected:
  //   unsigned short frame = 0;
  //   unsigned short framePeriod = 1;
  //   unsigned short reloadFrame = 0;
  //
  // public:
  //   bool isRealoading = false;
  //   bool isAvailable = false;
  //   bool isSelected = true;

public:
  Shotgun();
  Shotgun(Textures txt, Vector2 &position, float offset, float scale,
          int framePeriod);
  void draw(RayCollisionInfo &);
  void animate(Texture &);
  int getTextureOffset(int);
  void updateFrameCounter(unsigned short);
  // virtual int getFrame() = 0;
  // virtual void setFrame(unsigned short) = 0;
  // TODO: Shotgun logic
  ~Shotgun();
};
