#include "../include/usr/Demon.hpp"
#include "../include/usr/PathFinder.hpp"
#include <cmath>
#include <iostream>

Demon::Demon() : NPC() {};
Demon::Demon(Vector2 &pos) : NPC(pos) {
  if (Demon::textures.empty()) {
    Texture t11 = LoadTexture("textures/npc/caco_demon/idle/0.png");
    Texture t12 = LoadTexture("textures/npc/caco_demon/idle/1.png");
    Texture t13 = LoadTexture("textures/npc/caco_demon/idle/2.png");
    Texture t14 = LoadTexture("textures/npc/caco_demon/idle/3.png");
    Texture t15 = LoadTexture("textures/npc/caco_demon/idle/4.png");
    Texture t16 = LoadTexture("textures/npc/caco_demon/idle/5.png");
    Texture t17 = LoadTexture("textures/npc/caco_demon/idle/6.png");
    Texture t18 = LoadTexture("textures/npc/caco_demon/idle/7.png");
    Demon::textures[IDLE].push_back(t11);
    Demon::textures[IDLE].push_back(t12);
    Demon::textures[IDLE].push_back(t13);
    Demon::textures[IDLE].push_back(t14);
    Demon::textures[IDLE].push_back(t15);
    Demon::textures[IDLE].push_back(t16);
    Demon::textures[IDLE].push_back(t17);
    Demon::textures[IDLE].push_back(t18);
    Texture t21 = LoadTexture("textures/npc/caco_demon/attack/0.png");
    Texture t22 = LoadTexture("textures/npc/caco_demon/attack/1.png");
    Texture t23 = LoadTexture("textures/npc/caco_demon/attack/2.png");
    Texture t24 = LoadTexture("textures/npc/caco_demon/attack/3.png");
    Texture t25 = LoadTexture("textures/npc/caco_demon/attack/4.png");
    Demon::textures[ATTACK].push_back(t21);
    Demon::textures[ATTACK].push_back(t22);
    Demon::textures[ATTACK].push_back(t23);
    Demon::textures[ATTACK].push_back(t24);
    Demon::textures[ATTACK].push_back(t25);
    Texture t31 = LoadTexture("textures/npc/caco_demon/death/0.png");
    Texture t32 = LoadTexture("textures/npc/caco_demon/death/1.png");
    Texture t33 = LoadTexture("textures/npc/caco_demon/death/2.png");
    Texture t34 = LoadTexture("textures/npc/caco_demon/death/3.png");
    Texture t35 = LoadTexture("textures/npc/caco_demon/death/4.png");
    Demon::textures[DEATH].push_back(t31);
    Demon::textures[DEATH].push_back(t32);
    Demon::textures[DEATH].push_back(t33);
    Demon::textures[DEATH].push_back(t34);
    Demon::textures[DEATH].push_back(t35);
    Texture t41 = LoadTexture("textures/npc/caco_demon/walk/1.png");
    Demon::textures[WALK].push_back(t41);
    Texture t51 = LoadTexture("textures/npc/caco_demon/pain/0.png");
    Texture t52 = LoadTexture("textures/npc/caco_demon/pain/1.png");
    Demon::textures[PAIN].push_back(t31);
    Demon::textures[PAIN].push_back(t32);
  }
}

Demon::~Demon() {};

void Demon::update(Player &player, Map &map, int frame) {
  if (isAlive) {
    runLogic(player, map, frame);
  }
}
void Demon::runLogic(Player &player, Map &map, int frame) {
  frameCounter = frame;
  if (frameCounter & framePeriod) {
    triggerAnimation = true;
  }
  Vector2 ppos = player.getPosition();
  Vector2 selfpos = this->getPosition();
  Vector2 playerToSelf = (Vector2){ppos.x - selfpos.x, ppos.y - selfpos.y};
  bool playerSpotted = canSpotPlayer(player, map, frame);
  float distanceToPlayer = Vector2Length(playerToSelf);
  // cout << dirToMove.x << dirToMove.y << endl;

  // cout << state << endl;
  switch (state) {

  case NPCSTATE::IDLE: {
    if (Vector2Length(playerToSelf) < this->attackRange && playerSpotted) {
      isAggresive = true;
      this->changeState(NPCSTATE::WALK);
    }
    break;
  }
  case NPCSTATE::DEATH: {
    if (deathFrame >= 50) {

      isAlive = false;
      isVisible = false;
    }
    ++deathFrame;
  }
  case NPCSTATE::PAIN: {
    if (painFrame >= 20) {
      changeState(WALK);
      painFrame = 0;
      if (health < 0) {
        changeState(DEATH);
      }
    }

    ++painFrame;
  }
  case NPCSTATE::ATTACK: {
    if (playerSpotted) {
      if (frame % (framePeriod) == 0 && distanceToPlayer < (float)attackRange) {
        player.health -= (GetRandomValue(1, this->damage));
      }
    } else {
      changeState(WALK);
    }
  }
  case NPCSTATE::WALK: {
    move(dirToMove);
    if (frame % (framePeriod / 2) == 0) {
      if (distanceToPlayer < this->attackRange && playerSpotted) {
        isAggresive = true;
        if (distanceToPlayer < this->attackRange / 2) {
          changeState(ATTACK);
          break;
        }
      }
      if (distanceToPlayer > this->attackRange && !playerSpotted) {
        isAggresive = false;
      }
      PathFinder pf;
      if (!playerSpotted && !isAggresive) {
        changeState(IDLE);
        dirToMove = (Vector2){0, 0};
      } else {
        auto path = pf.findPath(map, ppos, selfpos);

        if (path.size() > 1) {
          cell target = path.at(path.size() - 1);
          if (target != make_pair(-1, -1)) {
            // DrawRectangle(target.first * WALL_SIZE / 5,
            //               target.second * WALL_SIZE / 5, WALL_SIZE / 5 - 1,
            //               WALL_SIZE / 5 - 1, PURPLE);
            dirToMove = (Vector2){
                (float)target.first * WALL_SIZE +
                    WALL_SIZE / (2 + GetRandomValue(0, 2)) - selfpos.x,
                (float)target.second * WALL_SIZE +
                    WALL_SIZE / (2 + GetRandomValue(0, 2)) - selfpos.y};
          }
        }
      }
    }
  }
  }
}

bool Demon::canSpotPlayer(Player &p, Map &map, int frame) {
  Vector2 pos = this->getPosition();
  Vector2 ppos = p.getPosition();
  Vector2 dir = Vector2Normalize(Vector2Subtract(ppos, pos));
  while (std::hypot(ppos.x - pos.x, ppos.y - pos.y) > 10) {
    pos = Vector2Add(pos, dir);
    if (map.at(pos.x / WALL_SIZE, pos.y / WALL_SIZE) != nullptr) {
      return false;
    }
  }
  return true;
}

void Demon::getDamage(Player &player, Map &map, int damage) {

  Vector2 pos = this->getPosition();
  Vector2 ppos = player.getPosition();
  Vector2 playerViewDir = Vector2Normalize(player.getViewDirection());
  float distanceToPlayer = std::hypot(ppos.x - pos.x, ppos.y - pos.y);
  Vector2 dir = Vector2Normalize(Vector2Subtract(pos, ppos));
  // if (Vector2Angle(playerViewDir, dir) > atan2(this->size, distanceToPlayer))
  // {
  //   return;
  // }

  while (distanceToPlayer > this->size) {
    ppos = Vector2Add(ppos, playerViewDir);
    distanceToPlayer = std::hypot(ppos.x - pos.x, ppos.y - pos.y);
    if (map.at(ppos.x / WALL_SIZE, ppos.y / WALL_SIZE) != nullptr) {
      return;
    }
  }
  cout << "damage " << damage << endl;
  cout << "health " << health << endl;
  health -= damage;
  changeState(PAIN);
}

void Demon::move(Vector2 dir) {
  dir = Vector2Normalize(dir);
  this->position.x += dir.x * speed;
  this->position.y += dir.y * speed;
}

int Demon::getTextureId(NPCSTATE s) {
  int textureNum = textures[s].size();
  switch (s) {
  case ATTACK:
    return (frameCounter / (textureNum * framePeriod) % textureNum);
  case IDLE:
    return (frameCounter / (framePeriod) / 2 % textureNum);
  case WALK:
    return (frameCounter % (textureNum * framePeriod) % textureNum);
  case PAIN:
    return (frameCounter / (textureNum * framePeriod) % textureNum);
  case DEATH:
    return (frameCounter % (textureNum * framePeriod) % textureNum);
  }
}

void Demon::changeState(NPCSTATE s) { state = s; }
bool Demon::affectPlayer(Player &) { return false; }

void Demon::draw(RayCollisionInfo &rci) {

  Texture txt = textures[state].at(getTextureId(state));
  float spriteWidth = txt.width;
  float spriteHeight = txt.height;

  float proj = SCREEN_DIST / rci.distance;
  float imageRatio = spriteWidth / spriteHeight;
  float projWidth = proj * spriteWidth * scale;
  float projHeight = proj * spriteHeight * scale;
  float spriteHalfWidth = projWidth / 2;
  float posx = rci.offset - spriteHalfWidth;
  float posy = WINDOWN_HALF_HEIGHT - (projHeight) / (2) + projHeight * offset;

  Rectangle source = Rectangle{0, 0, (float)spriteWidth, (float)spriteHeight};
  Rectangle dest = {posx, posy, projWidth, projHeight};
  DrawTexturePro(((txt)), source, dest, (Vector2){0, 0}, 0.0f, WHITE);
}
