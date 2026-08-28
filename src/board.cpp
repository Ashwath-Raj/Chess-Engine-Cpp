#include "board.h"
#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <vector>

// constructor
board::board()
{
    number_of_squares = 8;
}

void board::initialize()
{
    white_pieces_mask = 0xFFFF;             // 1111111111111111
    black_pieces_mask = 0xFFFF000000000000; // 1111111111111111000000000000000000000000000000000000000000000000

    pawn_mask = 0xFF00000000FF00;     // 11111111000000000000000000000000000000001111111100000000
    king_mask = 0x1000000000000010;   // 0001000000000000000000000000000000000000000000000000000000010000
    knight_mask = 0x4200000000000042; // 0100001000000000000000000000000000000000000000000000000001000010

    bishop_mask = 0x2400000000000024; // 0010010000000000000000000000000000000000000000000000000000100100
    queen_mask = 0x800000000000008;   // 100000000000000000000000000000000000000000000000000000001000
    rook_mask = 0x8100000000000081;   // 1000000100000000000000000000000000000000000000000000000010000001
}

void board::print_terminal()
{
    // masks must be utilized and print in terminal wp wR wH wB wK wQ  bp bR bH bB bK bQ
    for (int i = 0; i < 64; i++)
    {
        uint64_t read_mask = 0x1; // 0000000000000000000000000000000000000000000000000000000000000000
        // ex: i = 0 let first one be 1
        read_mask = 1ULL << i;

        // exists if yes color else continue
        if (white_pieces_mask & read_mask)
            std::cout << 'w';
        else if (black_pieces_mask & read_mask)
            std::cout << 'b';
        else
            std::cout << ".  ";

        if (pawn_mask & read_mask) // pawn
            std::cout << "p ";
        else if (king_mask & read_mask) // king
            std::cout << "k ";
        else if (knight_mask & read_mask) // horse
            std::cout << "h ";
        else if (bishop_mask & read_mask) // bishop
            std::cout << "c ";
        else if (queen_mask & read_mask) // queen
            std::cout << "q ";
        else if (rook_mask & read_mask) // rook
            std::cout << "r ";

        if ((i + 1) % 8 == 0)
            std::cout << std::endl;
    }
}
void board::drawGameBoardOnScreen(float pos_x, float pos_y, float square_size)
{
    /*=======================Draw Chess BOard Only==========================*/
    Color chess_board_white{238, 238, 210, 255};
    Color chess_board_selection{186, 202, 68, 255};
    Color chess_board_backGround{29, 54, 0, 255};
    Color chess_board_green{118, 150, 86, 255};

    // Draw Chess Board
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(chess_board_backGround);
        bool flag = true; // Black North / pc bot is  black
        pos_x = 100, pos_y = 10;
        int initial_pos_x = pos_x;
        square_size = 128.0;

        for (int i = 0; i < 8; i++)
        {
            if (flag)
            {
                for (int j = 0; j < 4; j++)
                { // loop draws all cols of a row
                    DrawRectangleV({pos_x, pos_y}, {square_size, square_size}, chess_board_green);
                    pos_x += square_size;
                    DrawRectangleV({pos_x, pos_y}, {square_size, square_size}, chess_board_white);
                    pos_x += square_size;
                }
                flag = false;
            }
            else
            {
                for (int j = 0; j < 4; j++)
                { // loop draws all cols of a row
                    DrawRectangleV({pos_x, pos_y}, {square_size, square_size}, chess_board_white);
                    pos_x += square_size;
                    DrawRectangleV({pos_x, pos_y}, {square_size, square_size}, chess_board_green);
                    pos_x += square_size;
                }
                flag = true;
            }
            pos_x = initial_pos_x;
            pos_y += square_size;
        }
        EndDrawing();

        /*=======================Places Peices On BOard==========================*/
    }
}

std::vector<std::vector<float>> postionToCordinates(float pos_x, float pos_y, float square_size)
{
    // generate cordinates to render peices
    std::vector<std::vector<float>> postion_to_cordinates = {{pos_x, pos_y}};
    float initial_pos_x = pos_x;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            postion_to_cordinates.push_back({pos_x, pos_y});
            pos_x += square_size;
            pos_y += square_size;
        }
        pos_x = initial_pos_x;
    }

    return postion_to_cordinates;
}

void drawGamepiecesOnScreen(float pos_x, float pos_y, float square_size)
{
    // generate cordinates to render peices
    std::vector<std::vector<float>> postion_to_cordinates = postionToCordinates(pos_x, pos_y, square_size);

    // render appropriate Game Pieces
    Texture2D demo_piece = LoadTexture("resources/bishop-b.svg");
    if (demo_piece.id == 0)
    {
        std::cout << "Error Loading demo_piece" << std::endl;
    }
}
