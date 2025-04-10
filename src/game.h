#include "grid.h"
#include "blocks.cpp"

struct Game
{
    Game();
    ~Game();

    void Draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    void rotateBlock();
    void lockBlock();
    void gameRestart();
    void updateScore(int linesCleared, int moveDownPoints);
    void gameDifficulty();
    bool blockFits();
    bool isBlockOutside();
    bool gameOver = false;
    bool blockSwapped = false;
    int playerScore = 0;
    double blockSpeed = 0.5;
    double lastMoveTime = 0;
    double moveDelay = 0.2;
    double blockReachedBottomTime = 0;

    Block getRandomBlock();
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Music music;
    Sound rotateSound;
    Sound clearSound;
    Sound blockPlaceSound;

    std::vector<Block> blocks;
    std::vector<Block> getAllBlocks();
};