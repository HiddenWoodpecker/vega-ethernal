
#include "../include/usr/MedPack.hpp"
#include <iostream>
MedPack::MedPack() : StaticSprite(){};
MedPack::MedPack(Textures txt, Vector2 &position, float offset, float scale)
    : StaticSprite(txt, position, offset, scale){};

void MedPack::draw(RayCollisionInfo &rci) {
  if (this->isVisible) {
    // std::cout << "inside draw";
    float spriteWidth = rci.txt->width;
    float spriteHeight = rci.txt->height;

    float proj = SCREEN_DIST / rci.distance;
    float imageRatio = spriteWidth / spriteHeight;
    float projWidth = proj * spriteWidth * scale;
    float projHeight = proj * spriteHeight * scale;
    float spriteHalfWidth = projWidth / 2;
    float posx = rci.offset - spriteHalfWidth;
    float posy = WINDOWN_HALF_HEIGHT - (projHeight) / (2) + projHeight * offset;

    Rectangle source = Rectangle{0, 0, (float)spriteWidth, (float)spriteHeight};
    Rectangle dest = {posx, posy, projWidth, projHeight};

    DrawTexturePro(*(rci.txt), source, dest, (Vector2){0, 0}, 0.0f, WHITE);
  }
}
bool MedPack::affectPlayer(Player &p) {
  Vector2 pos = p.getPosition();
  if (std::hypot(this->position.x - pos.x, this->position.y - pos.y) < 50.0f &&
      isVisible) {
    // TODO: medpack functionality
    p.rotateCamera(0.5f);
    this->isVisible = false;
    return true;
  }
  return false;
}
MedPack::~MedPack() {}
