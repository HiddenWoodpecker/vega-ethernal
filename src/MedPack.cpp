
#include "../include/usr/MedPack.hpp"
#include <iostream>
MedPack::MedPack() : StaticSprite(){};
MedPack::MedPack(Textures txt, Vector2 &position, int width, int height,
                 float scale)
    : StaticSprite(txt, position, width, height, scale){};

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
    float posy = WINDOWN_HALF_HEIGHT - (projHeight) / (2) + projHeight * 1.5f;

    Rectangle source = Rectangle{0, 0, (float)spriteWidth, (float)spriteHeight};
    Rectangle dest = {posx, posy, projWidth, projHeight};

    DrawTexturePro(*(rci.txt), source, dest, (Vector2){0, 0}, 0.0f, WHITE);
  }
}
bool MedPack::affectPlayer(Player &p) {
  Vector2 pos = p.getPosition();
  if (std::hypot(this->position.x - pos.x, this->position.y - pos.y) < 50.0f &&
      isVisible) {
    // TODO: ammopack functionality
    p.rotateCamera(0.0005f);
    this->isVisible = false;
    return true;
  }
  return false;
}
MedPack::~MedPack() {}
