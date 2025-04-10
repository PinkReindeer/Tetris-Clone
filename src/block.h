#pragma once
#include "position.h"
#include "colors.h"
#include <map>
#include <vector>
#include <array>

struct Block
{
    Block();
    
    void Draw(int offsetX, int offsetY);
    void Move(int row, int col);
    void rotate();
    void rotationFix();

    std::vector<Position> getCellPosition();
    std::map<int, std::vector<Position>> cells; 
    std::array<Color, 10> colors;

    int id;
    int cellSize = 50;
    int rotationState = 0;
    int rowOffset = 0;
    int colOffset = 0;
};