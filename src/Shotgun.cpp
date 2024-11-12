
#include "../include/usr/Shotgun.hpp"

#include <cmath>
#include <iostream>
Shotgun::Shotgun() : Weapon(){};
Shotgun::Shotgun(Textures txt, Vector2 &position, float offset, float scale,
                 int framePeriod)
    : Weapon(txt, position, offset, scale, 35){};
void Shotgun::draw(RayCollisionInfo &rci) {}
int Shotgun::getTextureOffset(int frame) {
  if (frame == 0 || !this->isRealoading) {
    return 0;
  }
  if (frame == 1) {
    return 120;
  }
  if (frame == 2) {
    return 120 + 150;
  }
  if (frame == 3) {
    return 120 + 150 + 100;
  }
  return 0;
}

float getSpriteWidth(int frame) {

  if (frame == 0) {
    return 120;
  }
  if (frame == 1) {
    return 150;
  }
  if (frame == 2) {
    return 100;
  }
  if (frame == 3) {
    return 130;
  }
  return 0;
}

void Shotgun::updateFrameCounter(unsigned short frame) {
  // if (isRealoading) {
  //   this->frame = frame % framePeriod;
  // } else {
  //   this->frame = 0;
  // }
}

void Shotgun::animate(Texture &txt) {
  float spriteWidth = getSpriteWidth(reloadFrame);
  float spriteHeight = txt.height;
  Rectangle source =
      Rectangle{(float)getTextureOffset(reloadFrame), 0,
                (float)getSpriteWidth(reloadFrame), (float)spriteHeight};
  std::cout << getSpriteWidth(reloadFrame) << std::endl;

  Rectangle dest = {WINDOW_WIDTH / 2 - spriteWidth * scale / 2,
                    WINDOW_HEIGHT - spriteHeight * scale, spriteWidth * scale,
                    spriteHeight * scale};
  DrawTexturePro(txt, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
  if (isRealoading) {

    reloadFrame = std::floor((float)frame / ((float)framePeriod / 4));
    std::cout << reloadFrame << std::endl;
    if (reloadFrame == 3 && frame + 2 > framePeriod) {
      this->isRealoading = false;
      reloadFrame = 0;
      frame = 0;
    }
    frame++;
  }
}
Shotgun::~Shotgun(){};
