#include "raylib.h"
#include <cstdlib>

#define WIN_WIDTH 600
#define WIN_HEIGHT 800
#define BLOCK_SIZE 50

typedef struct Block {
    int x;
    int y; 
    bool active; 
} Block;

Block blocks[10][16];

float timer = 0;
float gravity_time = 0.2; 

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            blocks[i][j] = {i + 1, j, false};
        }
    }

    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Tetris");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        timer += GetFrameTime();

        if (timer > gravity_time) {
            timer = 0; 
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 15; j++) {
                    if (blocks[i][j].active == true && blocks[i][j + 1].active == false) {
                        blocks[i][j + 1].active = true; 
                        blocks[i][j].active = false; 
                        break; 
                    }
                }
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = GetMouseX() / BLOCK_SIZE;
            int y = GetMouseY() / BLOCK_SIZE;
            if (x >= 1 && x < 11 && y >= 0 && y < 16) {
                blocks[x - 1][y].active = !blocks[x - 1][y].active;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 16; j++) {
                DrawRectangleLines(blocks[i][j].x * BLOCK_SIZE, blocks[i][j].y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, WHITE);
                if (blocks[i][j].active) {
                    DrawRectangle(blocks[i][j].x * BLOCK_SIZE, blocks[i][j].y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, WHITE);
                }
            }
        }

        

        EndDrawing();
    }

    return 0;
}