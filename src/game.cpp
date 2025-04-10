#include "game.h"
#include <random>
#include <iostream>

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    InitAudioDevice();
    music = LoadMusicStream("sound/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("sound/rotate.mp3");
    clearSound = LoadSound("sound/clear.mp3");
    blockPlaceSound = LoadSound("sound/blockPlace.mp3");
}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadSound(blockPlaceSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

std::vector<Block> Game::getAllBlocks()
{
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

Block Game::getRandomBlock()
{
    if(blocks.empty())
    {
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(15, 15);
    switch(nextBlock.id)
    {
        case 3:
            nextBlock.Draw(385, 320);
            break;
        case 4:
            nextBlock.Draw(390, 300);
            break;
        default:
            nextBlock.Draw(410, 300);
            break;
    }
}

void Game::handleInput()
{
    if (gameOver && IsKeyPressed(KEY_ENTER))
    {
        gameOver = false;
        gameRestart();
    }
    
    if (!gameOver)
    {
        double currentTime = GetTime();
        if (currentTime - lastMoveTime >= moveDelay)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                moveBlockLeft();
                lastMoveTime = currentTime;
                moveDelay = fmax(0.05, moveDelay - 0.02);
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                moveBlockRight();
                lastMoveTime = currentTime;
                moveDelay = fmax(0.05, moveDelay - 0.02);
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                moveBlockDown();
                if (blockReachedBottomTime == 0)
                {
                    updateScore(0, 1);
                }
                lastMoveTime = currentTime;
                moveDelay = fmax(0.05, moveDelay - 0.03);
            }
            else
            {
                moveDelay = 0.2;
            }
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            rotateBlock();
        }

        if (IsKeyPressed(KEY_R) && !blockSwapped)
        {
            Block tempBlock = currentBlock;
            currentBlock = nextBlock;
            nextBlock = getRandomBlock();

            if(!blockFits() || isBlockOutside())
            {
                nextBlock = currentBlock;
                currentBlock = tempBlock;
            }
            else
            {
                blockSwapped = true;
            }
        }

        if (blockReachedBottomTime > 0 && currentTime - blockReachedBottomTime >= 0.25)
        {
            lockBlock();
            blockReachedBottomTime = 0;
        }
    }
}

void Game::moveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.Move(0,-1);
        if (isBlockOutside() || !blockFits())
        {
            currentBlock.Move(0,1);
        }
    }
}

void Game::moveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.Move(0,1);
        if (isBlockOutside() || !blockFits())
        {
            currentBlock.Move(0,-1);
        }
    }
}

void Game::moveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.Move(1,0);
        if(isBlockOutside() || !blockFits())
        {
            currentBlock.Move(-1,0);
            if (blockReachedBottomTime == 0)
            {
                blockReachedBottomTime = GetTime();
            }
        }
        else
        {
            blockReachedBottomTime = 0;
        }
    }
}

void Game::rotateBlock()
{
    if (!gameOver)
    {
        currentBlock.rotate();
        if (isBlockOutside() || !blockFits())
        {
            currentBlock.rotationFix();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Game::lockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPosition();

    for (Position &item: tiles)
    {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    
    currentBlock = nextBlock;

    if (!blockFits())
    {
        gameOver = true;
    }
    else
    {
        PlaySound(blockPlaceSound);
    }

    nextBlock = getRandomBlock();

    int rowsCleared = grid.clearFullRow();
    if(rowsCleared > 0)
    {
        PlaySound(clearSound);
        updateScore(rowsCleared, 0);
    }

    blockSwapped = false;
}

void Game::gameRestart()
{
    grid.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    playerScore = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared)
    {
        case 1:
            playerScore += 100;
            break;
        case 2:
            playerScore += 300;
            break;
        case 3:
            playerScore += 500;
            break;
        case 4:
            playerScore += 800;
            break;
        default:
            break;
    }
    playerScore += moveDownPoints;
}

void Game::gameDifficulty()
{
    if (playerScore >= 1000 && blockSpeed == 0.5)
    {
        blockSpeed -= 0.1;
    }
    else if (playerScore >= 2500 && blockSpeed == 0.4)
    {
        blockSpeed -= 0.1;
    }
    else if (playerScore >= 5000 && blockSpeed == 0.3)
    {
        blockSpeed -= 0.1;
    }
    else if (playerScore >= 10000 && blockSpeed == 0.2)
    {
        blockSpeed -= 0.05;
    }
}

bool Game::blockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPosition();
    
    for (Position &item: tiles)
    {
        if (!grid.isCellEmpty(item.row, item.col))
        {
            return false;
        }
    }
    return true;
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPosition();
    for(Position &item : tiles)
    {
        if (grid.isCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}
