#include "../include/raylib-cpp.hpp"
#include "../include/usr/GameState.hpp"
#include <iostream>

int main() {

  int screenWidth = WINDOW_WIDTH;
  int screenHeight = WINDOW_HEIGHT;

  raylib::Color textColor(LIGHTGRAY);
  raylib::Window w(screenWidth, screenHeight, "VEGA Ethernal");

  SetTargetFPS(60);
  GameState gs;
  Map map = gs.getMap();
  Raycaster rc = gs.getRaycaster();
  Player player = gs.getPlayer();
  Renderer renderer = gs.getRenderer();
  while (!w.ShouldClose()) // Detect window close button or ESC key
  {
    // Draw
    BeginDrawing();
    // DrawTexture(txt, 100, 250, WHITE);
    ClearBackground(BLACK);
    // TODO: MAP DRAW
    // map.draw();
    // TODO raycast
    // renderer.renderObjects(spritesToDraw);
    gs.update();
    gs.manageControls();
    EndDrawing();
  }
  return 0;
}
