#include <cstdint>

/*
      Black
8 0 0 0 0 0 0 0 0
7 0 0 0 0 0 0 0 0
6 0 0 0 0 0 0 0 0
5 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0
3 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
a b c d e f g h
      White
*/
class player {
    private:
        bool turn; // white  = 1, black  = 0
        short int score; // pawn = 1, bishop = 3, knight= 3, rook = 5, queen = 8, king = INF/Win
};
class Board {       
    private:
        uint64_t white_pieces_mask = 0xFFFF;             //0000000000000000000000000000000000000000000000001111111111111111
        uint64_t black_pieces_mask = 0xFFFF000000000000; //1111111111111111000000000000000000000000000000000000000000000000

        uint64_t pawn_mask = 0xFF00000000FF00;           //0000000011111111000000000000000000000000000000001111111100000000
        uint64_t king_mask = 0x800000000000008;          //0000100000000000000000000000000000000000000000000000000000001000
        uint64_t knight_mask = 0x4400000000000044;       //0100010000000000000000000000000000000000000000000000000001000100
        
        uint64_t bishop_mask = 0x2400000000000024;       //0010010000000000000000000000000000000000000000000000000000100100
        uint64_t queen_mask = 0x1000000000000010;        //0001000000000000000000000000000000000000000000000000000000010000
        uint64_t rook_mask = 0x8100000000000081;         //1000000100000000000000000000000000000000000000000000000010000001

        void deletepeice(short int row, short int col, bool set_to) {
            uint64_t bit = 1L << (row *  8 + col);
            if(set_to == true) {
                white_pieces_mask |= bit;
                black_pieces_mask |= bit;
                pawn_mask |= bit;
                king_mask |= bit; 
                knight_mask |= bit; 
                bishop_mask |= bit; 
                queen_mask |= bit; 
                rook_mask |= bit; 
            }
            else {
                white_pieces_mask &= bit;
                black_pieces_mask &= bit;
                pawn_mask &= bit;
                king_mask &= bit; 
                knight_mask &= bit; 
                bishop_mask &= bit; 
                queen_mask &= bit; 
                rook_mask &= bit;
            }
        }

    public:
        void move(bool turn, short int col_from, short int row_from, short int col_to, short int row_to) {
            if(true) {  // islegal()
                if(true) { //kill
                    // add score to kill func
                }
                /*================move===========================*/ 
                // 1.delete anything in from and to square (set 0)
                deletepeice(row_from,col_from,false);
                deletepeice(row_to,col_to,false);

                // 2.Place that peice at to square
                uint64_t bit_from = 1L << (row_from *  8 + col_from);
                uint64_t bit_to = 1L << (row_to *  8 + col_to);
            
                if(pawn_mask & bit_from) 
                    pawn_mask |= bit_to;                
                else if(king_mask & bit_from) 
                    king_mask |= bit_to;                
                else if(knight_mask &= bit_from) 
                    knight_mask |= bit_to;             
                else if(bishop_mask & bit_from) 
                    bishop_mask |= bit_to;              
                else if(queen_mask & bit_from) 
                    queen_mask |= bit_to;
                else if(rook_mask & bit_from) 
                    rook_mask |= bit_to;
                
                // 3. Update Color BitBoard
                if(turn) // turn = 1 White
                    white_pieces_mask |= bit_to;
                else // turn  = 0 black
                    black_pieces_mask |= bit_to;
            }
            else {
                // invalid Move
            }
        }
        
                    
};