#include "../include/usr/Renderer.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void Renderer::loadTextures() {
  Texture t1 = LoadTexture("textures/wall1.png");
  Texture t2 = LoadTexture("textures/wall5.png");
  Texture t3 = LoadTexture("textures/wall3.png");
  Texture t4 = LoadTexture("textures/wall4.png");
  Texture t5 = LoadTexture("textures/wall4-1.png");
  Texture t6 = LoadTexture("textures/ammopack.png");
  Texture t7 = LoadTexture("textures/aid.png");
  Texture t8 = LoadTexture("textures/shotgun.png");
  textures.push_back(t1);
  textures.push_back(t2);
  textures.push_back(t3);
  textures.push_back(t4);
  textures.push_back(t5);
  // sprites
  textures.push_back(t6);
  textures.push_back(t7);
  textures.push_back(t8);
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
  std::sort(objectsToRender.begin(), objectsToRender.end(),
            [=](RayCollisionInfo &rci1, RayCollisionInfo &rci2) {
              return rci1.distance > rci2.distance;
            });
  for (int i = 0; i < objectsToRender.size(); ++i) {
    RayCollisionInfo rci = objectsToRender.at(i);
    if (rci.obj != nullptr) {
      rci.txt = &Renderer::getTexture(rci.obj->getTexture());
      rci.obj->draw(rci);
    } else {
      std::cout << "obj not found" << std::endl;

      std::cout << rci.isWallHit << std::endl;
    }
  }
}

void Renderer::renderWall(RayCollisionInfo &rci) {}
