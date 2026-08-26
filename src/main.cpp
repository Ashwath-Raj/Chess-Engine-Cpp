#include <iostream>
#include "board.h"
#include <raylib.h>

using namespace std;
int main(void) {
    cout << "Starting the Game" << endl;

    int game_window_width = 0, game_window_height = 0;
    const char *title = "Chess ENgine CPP"; 
    InitWindow(game_window_width, game_window_height, title);
    SetTargetFPS(60);
    





    /*=======================Draw Chess BOard Only==========================*/
    Color chess_board_white  {238, 238, 210, 255};
    Color chess_board_selection  {186, 202, 68, 255};
    Color chess_board_backGround {29, 54, 0, 255};
    Color chess_board_green {118, 150, 86, 255};

    // Draw Chess Board 
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(chess_board_backGround);
        bool flag = true; // Black North / pc bot is  black
        float pos_x = 100, pos_y = 10;

        for(int i = 0; i < 8; i++) {            
            if(flag) {
                for(int j = 0; j < 4; j++) {      // loop draws all cols of a row
                    DrawRectangleV({pos_x, pos_y}, {128, 128}, chess_board_green);
                    pos_x += 128.0;
                    DrawRectangleV({pos_x, pos_y}, {128, 128}, chess_board_white);
                    pos_x += 128.0;
                }
                flag = false;
            }
            else {
                for(int j = 0; j < 4; j++) {      // loop draws all cols of a row
                    DrawRectangleV({pos_x, pos_y}, {128, 128}, chess_board_white);
                    pos_x += 128.0;
                    DrawRectangleV({pos_x, pos_y}, {128, 128}, chess_board_green);
                    pos_x += 128.0;
                }
                flag = true;
            }
            pos_x = 100;
            pos_y += 128.0;
        }
        EndDrawing();
        

    /*=======================Places Peices On BOard==========================*/


    }
    
    
    CloseWindow();
    return 0;
}
