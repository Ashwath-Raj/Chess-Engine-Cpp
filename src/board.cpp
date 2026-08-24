#include "board.h"
#include <cstdint>
#include <iostream>

// constructor
board::board() {
    number_of_squares = 8;
    square_size = 98;
}

void board::initialize() {
    white_pieces_mask = 0xFFFF;                 // 1111111111111111 
    black_pieces_mask = 0xFFFF000000000000;     // 1111111111111111000000000000000000000000000000000000000000000000

    pawn_mask = 0xFF00000000FF00;               // 11111111000000000000000000000000000000001111111100000000         
    king_mask = 0x1000000000000010;             // 0001000000000000000000000000000000000000000000000000000000010000
    knight_mask = 0x4200000000000042;           // 0100001000000000000000000000000000000000000000000000000001000010

    bishop_mask = 0x2400000000000024;           // 0010010000000000000000000000000000000000000000000000000000100100   
    queen_mask = 0x800000000000008;      // 100000000000000000000000000000000000000000000000000000001000  
    rook_mask = 0x8100000000000081;      // 1000000100000000000000000000000000000000000000000000000010000001    
}

void board::print_terminal() {
    // masks must be utilized and print in terminal wp wR wH wB wK wQ  bp bR bH bB bK bQ
    for(int i = 0; i < 64; i++) {
        uint64_t read_mask = 0x1;    //0000000000000000000000000000000000000000000000000000000000000000
        // ex: i = 0 let first one be 1
        read_mask = 1ULL << i;
        
        // exists if yes color else continue
        if(white_pieces_mask & read_mask) 
            std::cout << 'w';
        else if(black_pieces_mask & read_mask) 
            std::cout << 'b';
        else 
            std::cout << ".  "; 
        
        if (pawn_mask & read_mask) // pawn
            std::cout << "p ";
        else if (king_mask & read_mask) // king
            std::cout << "k ";
        else if(knight_mask & read_mask)  // horse 
            std::cout << "h ";
        else if(bishop_mask & read_mask) // bishop
            std::cout << "c ";
        else if(queen_mask & read_mask) // queen
            std::cout << "q ";
        else if(rook_mask & read_mask) // rook
            std::cout << "r ";

        if((i + 1) % 8 == 0)
            std::cout << std::endl;
    }
}

// g++ D.cpp A.cpp B.cpp C.cpp main.cpp -o binman
// g++ board.h board.cpp main.cpp -o binman