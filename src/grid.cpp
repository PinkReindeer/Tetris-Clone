#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid()
{
    Initialize();
    colors = CellColors;
}

void Grid::Initialize()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << '\n';
    }
}

void Grid::Draw()
{
    for (int row = 0; row < numRows; ++row)
    {
        for(int col = 0; col < numCols; ++col)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 15, row * cellSize + 15, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

void Grid::clearRow(int row)
{
    for (int col = 0; col < numCols; ++col)
    {
        grid[row][col] = 0; 
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    for (int col = 0; col < numCols; ++col)
    {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

bool Grid::isCellOutside(int row, int col)
{
    return !(row >= 0 && row < numRows && col >= 0 && col < numCols);
}

bool Grid::isCellEmpty(int row, int col)
{
    return grid[row][col] == 0;
}

bool Grid::isRowFull(int row)
{
    for (int col = 0; col < numCols; ++col)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

int Grid::clearFullRow()
{
    int completed = 0;

    for (int row = numRows - 1; row >= 0; --row)
    {
        if(isRowFull(row))
        {
            clearRow(row);
            ++completed;
        }
        else if (completed > 0)
        {
            moveRowDown(row, completed);
        }
    }
    return completed;
}
