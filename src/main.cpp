#include <iostream>
#include "board.h"
#include <raylib.h>
#include <vector>

int main(void)
{
    board gameBoard; // Board Class Instance
    std::cout << "Starting the Game" << std::endl;
    int game_window_width = 0, game_window_height = 0;
    Color chess_board_backGround{29, 54, 0, 255};

    const char *title = "Chess ENgine CPP";
    InitWindow(game_window_width, game_window_height, title);
    SetTargetFPS(60);

    float pos_x = 100, pos_y = 10, square_size = 128.0;
    bool north_is_white = true; // Black North / pc bot is  black
    gameBoard.initialize(pos_x, pos_y, square_size, north_is_white);
    while (!WindowShouldClose())
    {
        ClearBackground(chess_board_backGround);
        BeginDrawing();
        gameBoard.drawGameBoardOnScreen(pos_x, pos_y, square_size);
        gameBoard.drawGamepiecesOnScreen(pos_x, pos_y, square_size); // Render Pieces
        EndDrawing();
    }

    /*=======================Places Peices On BOard==========================*/

    CloseWindow();
    return 0;
}