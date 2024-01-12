#include <iostream>
#include <raylib.h>
#include <raygui.h>

#include "var.h"
#include "gameManager.h"

Rectangle rec = { 10, 10, 100, 30 }; // GuiButton bounds
void InitGame(){
    std::cout << "bardoz journey" << std::endl;
    InitWindow(screenWidth, screenHeight, "bardoz journey");
    SetTargetFPS(framesPerSecond);
    return;
}
void Game(){
    while(!WindowShouldClose()){
        BeginDrawing();

        if (GuiButton(rec, "#05#Open Image")) { /* ACTION */ }
        ClearBackground(GRAY);
        DrawText("bardoz journey", 10, 10, 20, BLACK);
        EndDrawing();
    }
    return;
}
void EndGame(){
    CloseWindow();
    return;
}