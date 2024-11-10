#pragma once
#include "../raylib.hpp"
#include "Object.hpp"
#include <vector>
class Renderer {
private:
  std::vector<Texture> textures;

public:
  Renderer();
  ~Renderer();

  void loadTextures();
  void unloadTextures();
  Texture &getTexture(Textures);
  void drawTexture();
  void renderObjects(std::vector<RayCollisionInfo> &);
  void renderWall(RayCollisionInfo &);
  void renderStaticSprite(RayCollisionInfo &);
  void renderAnimatedSprite(RayCollisionInfo &);
};
