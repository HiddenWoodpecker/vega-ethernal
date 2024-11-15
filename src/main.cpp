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
    ClearBackground(BLACK);
    // DrawTexture(txt, 100, 250, WHITE);
    // TODO: MAP DRAW
    DrawCircle(gs.getPlayer().getPosition().x / 5,
               gs.getPlayer().getPosition().y / 5, 5, BLUE);
    // TODO raycast
    // renderer.renderObjects(spritesToDraw);
    gs.update();
    map.draw();
    EndDrawing();
  }
  return 0;
}
