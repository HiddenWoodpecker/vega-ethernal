#include "NPC.hpp"
class Demon : NPC {

  inline static std::unordered_map<NPCSTATE, std::vector<Texture>> textures;

public:
  Demon();
  Demon(Vector2 &);
  ~Demon();
  void update(Player &, Map &);
  void runLogic(Player &, Map &);
  void draw(RayCollisionInfo &);
  void changeState();
  bool affectPlayer(Player &);
};
