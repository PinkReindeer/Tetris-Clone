#include "block.h"
#include "position.h"

struct LBlock : Block
{
    LBlock()
    {
        id = 1;
        cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
        Move(0,3);
    }
};

struct JBlock : Block
{
    JBlock()
    {
        id = 2;
        cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(2,0)};
        Move(0,3);
    }
};

struct IBlock : Block
{
    IBlock()
    {
        id = 3;
        cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
        cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
        cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
        Move(-1,3);
    }
};

struct OBlock : Block
{
    OBlock()
    {
        id = 4;
        cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        Move(0,4);
    }
};

struct SBlock : Block
{
    SBlock()
    {
        id = 5;
        cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
        cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
        cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
        Move(0,3);
    }
};

struct TBlock : Block
{
    TBlock()
    {
        id = 6;
        cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
        Move(0,3);
    }
};

struct ZBlock : Block
{
    ZBlock()
    {
        id = 7;
        cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
        Move(0,3);
    }
};