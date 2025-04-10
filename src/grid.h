#pragma once
#include "raylib.h"
#include <array>

struct Grid
{
    Grid();

    void Initialize();
    void Print();
    void Draw();
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
    bool isCellOutside(int row, int col);
    bool isCellEmpty(int row, int col);
    bool isRowFull(int row);
    int clearFullRow();

    std::array<Color, 10> colors;

    int numRows = 16;
    int numCols = 10;
    int cellSize = 50;
    int grid[16][10];
};