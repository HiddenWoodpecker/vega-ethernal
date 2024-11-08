#include "../include/raylib-cpp.hpp"
#include "../include/usr/GameState.hpp"
#include <iostream>

int main() {

  int screenWidth = WINDOW_WIDTH;
  int screenHeight = WINDOW_HEIGHT;

  raylib::Color textColor(LIGHTGRAY);
  raylib::Window w(screenWidth, screenHeight, "VEGA Ethernal");

  Map map = Map();
  Raycaster rc = Raycaster();
  SetTargetFPS(60);
  GameState gs;
  Player player = gs.getPlayer();
  Renderer renderer = gs.getRenderer();
  while (!w.ShouldClose()) // Detect window close button or ESC key
  {
    // Draw
    BeginDrawing();
    // DrawTexture(txt, 100, 250, WHITE);
    //  DrawCircle(player.getPosition().x, player.getPosition().y, 10,
    //  raylib::Color(255, 0, 0, 125));
    ClearBackground(BLACK);
    // TODO: MAP DRAW
    // map.draw();
    // TODO raycast
    player.manageControls(map);
    std::vector<RayCollisionInfo> wallsToDraw =
        rc.raycast(player.getPosition(), player.getViewDirection(), map);
    // std::vector<RayCollisionInfo> spritesToDraw
    renderer.renderObjects(wallsToDraw);
    //  DrawLineEx(player.getPosition(),
    //             Vector2Add(player.getPosition(),
    //                        Vector2Scale(player.getViewDirection(), 30)),
    //             3, raylib::Color(RED));

    EndDrawing();
  }
  return 0;
}
