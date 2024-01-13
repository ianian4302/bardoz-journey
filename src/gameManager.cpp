#include <iostream>
#include <raylib.h>
#include <raygui.h>

#include "var.h"
#include "gameManager.h"

Rectangle rec = {100, 100, 300, 300}; // GuiButton bounds
void InitGame()
{
    std::cout << "bardoz journey" << std::endl;
    InitWindow(screenWidth, screenHeight, "bardoz journey");
    DefaultValues();
    SetTargetFPS(framesPerSecond);
    return;
}
void DefaultValues()
{
    GuiSetStyle(DEFAULT, TEXT_SIZE, fontSize);
    GuiSetIconScale(iconScale);
    return;
}
void EndGame()
{
    CloseWindow();
    return;
}
void movement()
{

    return;
}
void SettingDisplay()
{
    DrawFPS(10, 10);
    DrawText("bardoz journey", screenWidth - MeasureText("bardoz journey", buttnonTitleSize), screenHeight - buttnonTitleSize, buttnonTitleSize, WHITE);
}
void Game()
{

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        MeasureText("bardoz journey", 40);
        SettingDisplay();


        if (GuiButton(rec, "#05#Open Image"))
        {
            
        }
        EndDrawing();
    }
    return;
}