#pragma once
#include <cstdint>

class board {
public:
    board();
    void initialize();
    void print_terminal();

private:
    int number_of_squares;
    int square_size;
    uint64_t white_pieces_mask; 
    uint64_t black_pieces_mask; 

    uint64_t pawn_mask;   
    uint64_t king_mask;   
    uint64_t knight_mask; 

    uint64_t bishop_mask; 
    uint64_t queen_mask;  
    uint64_t rook_mask;   
};

// temp uint64_t& white_pieces_mask, uint64_t &black_pieces_mask, uint64_t &pawn_mask, uint64_t &king_mask, uint64_t &knight_mask, uint64_t &bishop_mask, uint64_t &queen_mask, uint64_t &rook_mask