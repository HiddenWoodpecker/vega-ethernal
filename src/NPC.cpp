#include "../include/usr/NPC.hpp"

NPC::NPC() : StaticSprite() {};
NPC::~NPC() {};
NPC::NPC(Vector2 &pos) : StaticSprite(Textures::SHELLPACK, pos, 1.0f, 0.5f) {};

Demon::Demon() : NPC() {};
Demon::Demon(Vector2 &pos) : NPC(pos) {
  Texture t11 = LoadTexture("textures/npc/caco_demon/idle/0.png");
  Texture t12 = LoadTexture("textures/npc/caco_demon/idle/1.png");
  Texture t13 = LoadTexture("textures/npc/caco_demon/idle/2.png");
  Texture t14 = LoadTexture("textures/npc/caco_demon/idle/3.png");
  Texture t15 = LoadTexture("textures/npc/caco_demon/idle/4.png");
  Texture t16 = LoadTexture("textures/npc/caco_demon/idle/5.png");
  Texture t17 = LoadTexture("textures/npc/caco_demon/idle/6.png");
  Texture t18 = LoadTexture("textures/npc/caco_demon/idle/7.png");
  textures.at(IDLE).push_back(t11);
  textures.at(IDLE).push_back(t12);
  textures.at(IDLE).push_back(t13);
  textures.at(IDLE).push_back(t14);
  textures.at(IDLE).push_back(t15);
  textures.at(IDLE).push_back(t16);
  textures.at(IDLE).push_back(t17);
  textures.at(IDLE).push_back(t18);
  Texture t21 = LoadTexture("textures/npc/caco_demon/attack/0.png");
  Texture t22 = LoadTexture("textures/npc/caco_demon/attack/1.png");
  Texture t23 = LoadTexture("textures/npc/caco_demon/attack/2.png");
  Texture t24 = LoadTexture("textures/npc/caco_demon/attack/3.png");
  Texture t25 = LoadTexture("textures/npc/caco_demon/attack/4.png");
  textures.at(ATTACK).push_back(t21);
  textures.at(ATTACK).push_back(t22);
  textures.at(ATTACK).push_back(t23);
  textures.at(ATTACK).push_back(t24);
  textures.at(ATTACK).push_back(t25);
  Texture t31 = LoadTexture("textures/npc/caco_demon/death/0.png");
  Texture t32 = LoadTexture("textures/npc/caco_demon/death/1.png");
  Texture t33 = LoadTexture("textures/npc/caco_demon/death/2.png");
  Texture t34 = LoadTexture("textures/npc/caco_demon/death/3.png");
  Texture t35 = LoadTexture("textures/npc/caco_demon/death/4.png");
  textures.at(DEATH).push_back(t31);
  textures.at(DEATH).push_back(t32);
  textures.at(DEATH).push_back(t33);
  textures.at(DEATH).push_back(t34);
  textures.at(DEATH).push_back(t35);
}
