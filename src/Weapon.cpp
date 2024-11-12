#include "../include/usr/Weapon.hpp"

#include <iostream>
Weapon::Weapon() : Sprite(){};
Weapon::Weapon(Textures txt, Vector2 &position, float offset, float scale,
               int framePeriod)
    : Sprite(txt, position, offset, scale), framePeriod(framePeriod){};
// void Weapon::draw(RayCollisionInfo &rci) {}
// void Weapon::animate(Player &p) {}
Weapon::~Weapon(){};
