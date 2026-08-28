#include <iostream>
#include "board.h"
#include <raylib.h>
#include <vector>

int main(void)
{
    board gameBoard; // Board Class Instance
    gameBoard.initialize();

    std::cout << "Starting the Game" << std::endl;
    int game_window_width = 0, game_window_height = 0;
    const char *title = "Chess ENgine CPP";
    InitWindow(game_window_width, game_window_height, title);
    SetTargetFPS(60);

    float pos_x = 100, pos_y = 10, square_size = 128.0;
    while (!WindowShouldClose())
    {
        gameBoard.drawGamepiecesOnScreen(pos_x, pos_y, square_size); // Render Pieces
        gameBoard.drawGameBoardOnScreen(pos_x, pos_y, square_size); // Render Game Board
    }

    /*=======================Places Peices On BOard==========================*/
    CloseWindow();
    return 0;
}