#include "NPC.hpp"
class Demon : public NPC {

  Vector2 dirToMove = {0, 0};
  inline static std::unordered_map<NPCSTATE, std::vector<Texture>> textures;

public:
  Demon();
  Demon(Vector2 &);
  ~Demon();
  void update(Player &, Map &, int);
  bool canSpotPlayer(Player &, Map &, int);
  void move(Vector2);
  void runLogic(Player &, Map &, int);
  void draw(RayCollisionInfo &);
  void changeState(NPCSTATE);
  bool affectPlayer(Player &);
};
