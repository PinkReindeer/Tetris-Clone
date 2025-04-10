#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

//  Function to check if a certain time interval has passed
//  since the last update. This is used to control the speed of the game.
bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(750, 830, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("font/AovelSansRounded-rdDL.ttf", 64, 0, 0);
    Game game;

    while(!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.handleInput();
        game.gameDifficulty();
        if (eventTriggered(game.blockSpeed))
        {
            game.moveBlockDown();
        }
        BeginDrawing();
            ClearBackground(darkBlue);
            DrawTextEx(font, "Score", {575, 20}, 50, 2, WHITE);
            DrawTextEx(font, "Next", {588, 200}, 50, 2, WHITE);

            if (game.gameOver)
            {
                DrawTextEx(font, "GAME OVER!!", {525, 600}, 40, 2, WHITE);
            }

            DrawRectangleRounded({535, 70, 200, 75}, 0.3, 6, lightBlue);

            char scoreText[10];
            sprintf(scoreText, "%d", game.playerScore);
            Vector2 textSize = MeasureTextEx(font, scoreText, 50, 2);

            DrawTextEx(font, scoreText, {550 + (170 - textSize.x) / 2, 80}, 50, 2, WHITE);

            DrawRectangleRounded({530, 250, 210, 200}, 0.3, 6, lightBlue);
            game.Draw();
        EndDrawing();
    }

    CloseWindow();
}