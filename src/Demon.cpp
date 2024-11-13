#include "../include/usr/Demon.hpp"

Demon::Demon() : NPC() {};
Demon::Demon(Vector2 &pos) : NPC(pos) {
  if (!Demon::textures.empty()) {
    Texture t11 = LoadTexture("textures/npc/caco_demon/idle/0.png");
    Texture t12 = LoadTexture("textures/npc/caco_demon/idle/1.png");
    Texture t13 = LoadTexture("textures/npc/caco_demon/idle/2.png");
    Texture t14 = LoadTexture("textures/npc/caco_demon/idle/3.png");
    Texture t15 = LoadTexture("textures/npc/caco_demon/idle/4.png");
    Texture t16 = LoadTexture("textures/npc/caco_demon/idle/5.png");
    Texture t17 = LoadTexture("textures/npc/caco_demon/idle/6.png");
    Texture t18 = LoadTexture("textures/npc/caco_demon/idle/7.png");
    Demon::textures.at(IDLE).push_back(t11);
    Demon::textures.at(IDLE).push_back(t12);
    Demon::textures.at(IDLE).push_back(t13);
    Demon::textures.at(IDLE).push_back(t14);
    Demon::textures.at(IDLE).push_back(t15);
    Demon::textures.at(IDLE).push_back(t16);
    Demon::textures.at(IDLE).push_back(t17);
    Demon::textures.at(IDLE).push_back(t18);
    Texture t21 = LoadTexture("Demon::textures/npc/caco_demon/attack/0.png");
    Texture t22 = LoadTexture("Demon::textures/npc/caco_demon/attack/1.png");
    Texture t23 = LoadTexture("Demon::textures/npc/caco_demon/attack/2.png");
    Texture t24 = LoadTexture("Demon::textures/npc/caco_demon/attack/3.png");
    Texture t25 = LoadTexture("Demon::textures/npc/caco_demon/attack/4.png");
    Demon::textures.at(ATTACK).push_back(t21);
    Demon::textures.at(ATTACK).push_back(t22);
    Demon::textures.at(ATTACK).push_back(t23);
    Demon::textures.at(ATTACK).push_back(t24);
    Demon::textures.at(ATTACK).push_back(t25);
    Texture t31 = LoadTexture("Demon::textures/npc/caco_demon/death/0.png");
    Texture t32 = LoadTexture("Demon::textures/npc/caco_demon/death/1.png");
    Texture t33 = LoadTexture("Demon::textures/npc/caco_demon/death/2.png");
    Texture t34 = LoadTexture("Demon::textures/npc/caco_demon/death/3.png");
    Texture t35 = LoadTexture("Demon::textures/npc/caco_demon/death/4.png");
    Demon::textures.at(DEATH).push_back(t31);
    Demon::textures.at(DEATH).push_back(t32);
    Demon::textures.at(DEATH).push_back(t33);
    Demon::textures.at(DEATH).push_back(t34);
    Demon::textures.at(DEATH).push_back(t35);
    Texture t41 = LoadTexture("Demon::textures/npc/caco_demon/walk/1.png");
    Demon::textures.at(WALK).push_back(t41);
    Texture t51 = LoadTexture("Demon::textures/npc/caco_demon/pain/0.png");
    Texture t52 = LoadTexture("Demon::textures/npc/caco_demon/pain/1.png");
    Demon::textures.at(PAIN).push_back(t31);
    Demon::textures.at(PAIN).push_back(t32);
  }
}

Demon::~Demon() {};

void Demon::update(Player &, Map &) {}
void Demon::runLogic(Player &, Map &) {}
void Demon::draw(RayCollisionInfo &) {}
void Demon::changeState() {}
bool Demon::affectPlayer(Player &) {}
