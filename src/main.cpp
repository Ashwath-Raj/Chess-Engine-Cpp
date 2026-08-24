#include<iostream>
#include<raylib.h>

using namespace std;

int main(void) {
    cout << "Starting the Game" << endl;
    
    const int screen_width = 1280;
    const int screen_height = 800;
    
    InitWindow(screen_width, screen_height, "Test WIndow");
    SetTargetFPS(60);

    while(WindowShouldClose() == false) {
        BeginDrawing();
        EndDrawing();
        cout << "Window is open!!" << endl;
    }
    CloseWindow();
    return 0;
}