#include <iostream>
#include <raylib.h>
#include <raygui.h>

#include "var.h"
#include "gameManager.h"

Rectangle rec = {200, 200, 200, 60};  // GuiButton bounds
Rectangle rec2 = {200, 100, 200, 20}; // GuiButton bounds
float speed = 4.0f;                   // GuiSlider value

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
    //set text color to black
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, 0x000000ff);
    GuiSetIconScale(iconScale);
    return;
}
void EndGame()
{
    CloseWindow();
    return;
}
void movement(Texture2D texture, Vector2 &position)
{
    if (IsKeyDown(KEY_W) && position.y > 0)
        position.y -= speed;
    if (IsKeyDown(KEY_S) && position.y < screenHeight - texture.height)
        position.y += speed;
    if (IsKeyDown(KEY_A) && position.x > 0)
        position.x -= speed;
    if (IsKeyDown(KEY_D) && position.x < screenWidth - texture.width)
        position.x += speed;
    if (position.x < 0)
        position.x = 0.0f;
    if (position.x > screenWidth - texture.width)
        position.x = (float)screenWidth - texture.width;
    if (position.y < 0)
        position.y = 0.0f;
    if (position.y > screenHeight - texture.height)
        position.y = (float)screenHeight - texture.height;
    return;
}
void SettingDisplay()
{
    DrawFPS(10, 10);
    DrawText("bardoz journey", screenWidth - MeasureText("bardoz journey", buttnonTitleSize), screenHeight - buttnonTitleSize, buttnonTitleSize, WHITE);
}
void Game()
{
    Image image = LoadImage("assets/slime.png");
    ImageResizeNN(&image, 120, 100);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    Vector2 origin = {(float)screenWidth / 2 - texture.width / 2, (float)screenHeight / 2 - texture.height / 2};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        MeasureText("bardoz journey", 40);
(float)GuiSliderBar(rec2, "MinSpeed", "MaxSpeed", &speed, 0, 10);
        DrawTexture(texture, (int)origin.x, (int)origin.y, WHITE);
        movement(texture, origin);
        
        if (GuiButton(rec, "speed"))
            std::cout << "speed: " << GuiGetStyle(DEFAULT, 18) << std::endl;
        SettingDisplay();
        EndDrawing();
    }
    UnloadTexture(texture);
    return;
}