#include <iostream>
#include "board.h"
#include <raylib.h>

using namespace std;

int main(void) {
    cout << "Starting the Game" << endl;
    board chess = board();
    chess.initialize();
    chess.print_terminal();
    return 0;
}