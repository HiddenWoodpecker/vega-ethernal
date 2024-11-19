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
  while (!w.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    gs.update();
    EndDrawing();
  }
  return 0;
}
