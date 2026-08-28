#pragma once
#include <cstdint>
#include <vector>


class board
{
public:
    board();
    void initialize(float pos_x, float pos_y, float square_size);
    void print_terminal();
    std::vector<bool> drawGamepiecesOnScreen(float pos_x, float pos_y, float square_size);
    void drawGameBoardOnScreen(float pos_x, float pos_y, float square_size, std::vector<bool> piece_exists_mp);
    std::vector<std::vector<float>> postionToCordinates(float pos_x, float pos_y, float square_size);

private:
    int number_of_squares;
    uint64_t white_pieces_mask;
    uint64_t black_pieces_mask;

    uint64_t pawn_mask;
    uint64_t king_mask;
    uint64_t knight_mask;

    uint64_t bishop_mask;
    uint64_t queen_mask;
    uint64_t rook_mask;

    std::vector<std::vector<float>> postion_to_cordinates;
   
};

// temp uint64_t& white_pieces_mask, uint64_t &black_pieces_mask, uint64_t &pawn_mask, uint64_t &king_mask, uint64_t &knight_mask, uint64_t &bishop_mask, uint64_t &queen_mask, uint64_t &rook_mask