#include "../include/usr/Sprite.hpp"

Sprite::Sprite() : Object(){};
Sprite::Sprite(Textures txt, Vector2 &position, float offset, float scale)
    : Object(position, txt), offset(offset), scale(scale){};

Sprite::~Sprite(){};
