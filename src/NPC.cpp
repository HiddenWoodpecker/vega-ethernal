#include "../include/usr/NPC.hpp"

NPC::NPC() : StaticSprite() {};
NPC::~NPC() {};
NPC::NPC(Vector2 &pos) : StaticSprite(Textures::SHELLPACK, pos, 1.0f, 0.5f) {};
