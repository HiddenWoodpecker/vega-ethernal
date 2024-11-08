#include "../include/usr/Renderer.hpp"

void Renderer::loadTextures() {
  Texture t1 = LoadTexture("textures/wall1.png");
  Texture t2 = LoadTexture("textures/wall2.png");
  Texture t3 = LoadTexture("textures/wall3.png");
  Texture t4 = LoadTexture("textures/wall4.png");
  Texture t5 = LoadTexture("textures/wall4-1.png");
  textures.push_back(t1);
  textures.push_back(t2);
  textures.push_back(t3);
  textures.push_back(t4);
  textures.push_back(t5);
}
void Renderer::unloadTextures() {
  for (auto t : textures) {
    UnloadTexture(t);
  }
}
Renderer::Renderer() : textures() { loadTextures(); }
Renderer::~Renderer() { unloadTextures(); }

Texture &Renderer::getTexture(Textures t) { return textures.at(t); }

void Renderer::renderObjects(std::vector<RayCollisionInfo> &objectsToRender) {

  for (int i = 0; i < objectsToRender.size(); ++i) {
    RayCollisionInfo rci = objectsToRender.at(i);
    if (rci.obj != nullptr) {
      rci.txt = &Renderer::getTexture(rci.obj->getTexture());
      rci.obj->draw(rci);
    }
  }
}

void Renderer::renderWall(RayCollisionInfo &rci) {}
