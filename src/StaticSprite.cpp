#include "../include/usr/StaticSprite.hpp"

StaticSprite::StaticSprite() : Sprite(){};
StaticSprite::StaticSprite(Textures txt, Vector2 &position, int width,
                           int height)
    : Sprite(txt, position, width, height){};

StaticSprite::~StaticSprite(){};
