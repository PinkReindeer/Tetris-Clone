This project is a modified and improved version of the original [Cpp-Tetris-Game-with-raylib](https://github.com/educ8s/Cpp-Tetris-Game-with-raylib) by **educ8s**.

Tetris-Clone is a terminal-based Tetris game built with C++ and the [raylib](https://www.raylib.com/) graphics library. This version features improvements to the visuals and added gameplay functionality, aiming to create a smoother and more enjoyable experience.

## Features

- Classic Tetris gameplay
- Clean and modern graphics (powered by raylib)
- Improved user experiments compared to original
- New features added:
  - Difficulty increase base on player's score
  - Move block continuosly
  - Adding time that allow player can rotate after block is fit
  - Improve performace and memory

## Installation

### Prerequisites

- C++14 or later
- raylib installed on your system

### On Windows (using MSYS2 or MinGW)

```bash
g++ main.cpp -o tetris -lraylib -lopengl32 -lgdi32 -lwinmm
