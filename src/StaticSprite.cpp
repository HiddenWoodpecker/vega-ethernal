#include "../include/usr/StaticSprite.hpp"

StaticSprite::StaticSprite() : Sprite(){};
StaticSprite::StaticSprite(Textures txt, Vector2 &position, float offset,
                           float scale)
    : Sprite(txt, position, offset, scale){};

StaticSprite::~StaticSprite(){};
