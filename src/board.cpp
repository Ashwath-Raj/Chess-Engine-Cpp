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

std::vector<std::vector<float>> board::postionToCordinates(float pos_x, float pos_y, float square_size)
{
    // generate cordinates to render peices
    std::vector<std::vector<float>> postion_to_cordinates_ = {{pos_x, pos_y}};
    float initial_pos_x = pos_x;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            postion_to_cordinates_.push_back({pos_x, pos_y});
            std::cout << "{" << pos_x << ", " << pos_y << "} ";
            pos_x += square_size;
        }
        pos_x = initial_pos_x;
        pos_y += square_size;
    }
    return postion_to_cordinates_;
}

void board::initialize(float pos_x, float pos_y, float square_size)
{
    white_pieces_mask = 0xFFFF;             // 1111111111111111
    black_pieces_mask = 0xFFFF000000000000; // 1111111111111111000000000000000000000000000000000000000000000000

    pawn_mask = 0xFF00000000FF00;     // 11111111000000000000000000000000000000001111111100000000
    king_mask = 0x1000000000000010;   // 0001000000000000000000000000000000000000000000000000000000010000
    knight_mask = 0x4200000000000042; // 0100001000000000000000000000000000000000000000000000000001000010

    bishop_mask = 0x2400000000000024; // 0010010000000000000000000000000000000000000000000000000000100100
    queen_mask = 0x800000000000008;   // 100000000000000000000000000000000000000000000000000000001000
    rook_mask = 0x8100000000000081;   // 1000000100000000000000000000000000000000000000000000000010000001

    postion_to_cordinates = postionToCordinates(pos_x, pos_y, square_size);
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
void board::drawGameBoardOnScreen(float pos_x, float pos_y, float square_size, std::vector<bool>)
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

        /*=======================Places Pieces On BOard==========================*/
    }
}


std::vector<bool> board::drawGamepiecesOnScreen(float pos_x, float pos_y, float square_size)
{
    // generate cordinates to render peices
    // domne in intialize static std::vector<std::vector<float>> postion_to_cordinates = postionToCordinates(pos_x, pos_y, square_size);

    // check if pieces are rendered
    // render appropriate Game Pieces
    static Texture2D black_pawn_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/pawn-b.png");
    static Texture2D black_king_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/king-b.png");
    static Texture2D black_queen_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/queen-b.png");
    static Texture2D black_rook_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/rook-b.png");
    static Texture2D black_knight_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/knight-b.png");
    static Texture2D black_bishop_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/bishop-b.png");

    static Texture2D white_pawn_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/pawn-w.png");
    static Texture2D white_king_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/king-w.png");
    static Texture2D white_queen_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/queen-w.png");
    static Texture2D white_rook_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/rook-w.png");
    static Texture2D white_knight_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/knight-w.png");
    static Texture2D white_bishop_texure = LoadTexture("/home/ashwathraj/Acadimics/3.Semister3/Projects/Chess Engine/ChessEngine-cppBuilder/resources/bishop-w.png");

    if (black_pawn_texure.id == 0)
        std::cout << "black_pawn_texure not rendering";
    else if (black_king_texure.id == 0)
        std::cout << "black_king_texure not rendering";
    else if (black_queen_texure.id == 0)
        std::cout << "black_queen_texure not rendering";
    else if (black_rook_texure.id == 0)
        std::cout << "black_rook_texure not rendering";
    else if (black_knight_texure.id == 0)
        std::cout << "black_knight_texure not rendering";
    else if (black_bishop_texure.id == 0)
        std::cout << "black_bishop_texure not rendering";

    if (white_pawn_texure.id == 0)
        std::cout << "white_pawn_texure not rendering";
    else if (white_king_texure.id == 0)
        std::cout << "white_king_texure not rendering";
    else if (white_queen_texure.id == 0)
        std::cout << "white_queen_texure not rendering";
    else if (white_rook_texure.id == 0)
        std::cout << "white_rook_texure not rendering";
    else if (white_knight_texure.id == 0)
        std::cout << "white_knight_texure not rendering";
    else if (white_bishop_texure.id == 0)
        std::cout << "white_bishop_texure not rendering";

    std::vector<bool> piece_exists_mp;
    // masks must be utilized and print in terminal wp wR wH wB wK wQ  bp bR bH bB bK bQ
    for (int i = 0; i < 64; i++)
    {
        uint64_t read_mask = 0x1; // 0000000000000000000000000000000000000000000000000000000000000000
        // ex: i = 0 let first one be 1
        read_mask = 1ULL << i;
        std::vector<float> cords_raw = postion_to_cordinates[i];
        Vector2 cords;
        
        cords.x = postion_to_cordinates[i][0];
        cords.y = postion_to_cordinates[i][1];

        piece_exists_mp.push_back(true);

        // exists if yes color else continue
        bool iswhite;
        if (white_pieces_mask & read_mask) 
            iswhite = true;
        else if (black_pieces_mask & read_mask) 
            iswhite = false;
        else    
            piece_exists_mp[i] = false;

        if (pawn_mask & read_mask) {            // pawn
            if(iswhite)
                DrawTextureV(white_pawn_texure, cords, WHITE);
            else 
                DrawTextureV(black_pawn_texure, cords, WHITE);
        }
        else if (king_mask & read_mask) {       // king
            if(iswhite)
                DrawTextureV(white_king_texure, cords, WHITE);
            else 
                DrawTextureV(black_king_texure, cords, WHITE);
        }
        else if (knight_mask & read_mask) {         // horse
            if(iswhite)
                DrawTextureV(white_knight_texure, cords, WHITE);
            else 
                DrawTextureV(black_knight_texure, cords, WHITE);
        }
        else if (bishop_mask & read_mask) {     // bishop
            if(iswhite)
                DrawTextureV(white_bishop_texure, cords, WHITE);
            else 
                DrawTextureV(black_bishop_texure, cords, WHITE);
        }
        else if (queen_mask & read_mask) {      // queen
            if(iswhite)
                DrawTextureV(white_queen_texure, cords, WHITE);
            else 
                DrawTextureV(black_queen_texure, cords, WHITE);
        }
        else if (rook_mask & read_mask) {       // rook
            if(iswhite)
                DrawTextureV(white_rook_texure, cords, WHITE);
            else 
                DrawTextureV(black_rook_texure, cords, WHITE);
        }
    }
    return piece_exists_mp;

    UnloadTexture(black_pawn_texure);
    UnloadTexture(black_king_texure);
    UnloadTexture(black_queen_texure);
    UnloadTexture(black_rook_texure);
    UnloadTexture(black_knight_texure);
    UnloadTexture(black_bishop_texure);
    UnloadTexture(white_pawn_texure);
    UnloadTexture(white_king_texure);
    UnloadTexture(white_queen_texure);
    UnloadTexture(white_rook_texure);
    UnloadTexture(white_knight_texure);
    UnloadTexture(white_bishop_texure);


}
// DrawTextureV(texure, {x, y}, WHITE)