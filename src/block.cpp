#include "block.h"

Block::Block()
{
    colors = CellColors;
}

void Block::Draw(int offsetX, int offsetY)
{
    const std::vector<Position> &tiles = getCellPosition();

    for(const Position &item: tiles)
    {
        DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int row, int col)
{
    rowOffset += row;
    colOffset += col;
}

void Block::rotate()
{
    rotationState = (rotationState + 1) % (int)cells.size();
    // ++rotationState;
    // if (rotationState == (int)cells.size())
    // {
    //     rotationState = 0;
    // }
}

void Block::rotationFix()
{
    rotationState = (rotationState - 1 + (int)cells.size()) % (int)cells.size();
    // --rotationState;
    // if(rotationState == -1)
    // {
    //     rotationState = (int)cells.size() - 1;
    // }
}

std::vector<Position> Block::getCellPosition()
{
    const std::vector<Position> &tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    movedTiles.reserve(tiles.size());
    for (const Position &item: tiles)
    {
        movedTiles.emplace_back(item.row + rowOffset, item.col + colOffset);
    }
    return movedTiles;
}