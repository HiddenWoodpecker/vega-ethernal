
#include "../include/usr/AmmoPack.hpp"
#include <iostream>
AmmoPack::AmmoPack() : StaticSprite(){};
AmmoPack::AmmoPack(Textures txt, Vector2 &position, int width, int height)
    : StaticSprite(txt, position, width, height){};
void AmmoPack::draw(RayCollisionInfo &rci) {
  // std::cout << "inside draw";
  float proj = SCREEN_DIST / rci.distance;
  float imageRatio = rci.txt->width / rci.txt->height;
  float projWidth = proj * rci.txt->width;
  float projHeight = proj * rci.txt->height;
  float spriteHalfWidth = projWidth / 2;
  float posx = rci.offset - spriteHalfWidth;
  float posy = WINDOWN_HALF_HEIGHT - (projHeight) / (2) + projHeight * 1.5f;
  Rectangle r = Rectangle{0, 0, (float)rci.txt->width, (float)rci.txt->height};

  Rectangle dest = {posx, posy, projWidth, projHeight};
  DrawTexturePro(*(rci.txt), r, dest, (Vector2){0, 0}, 0.0f, WHITE);
}
void AmmoPack::affectPlayer(Player &p) { p.rotateCamera(0.5f); }
AmmoPack::~AmmoPack(){};
