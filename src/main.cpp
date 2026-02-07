#include "raylib.h"

#define WIN_WIDTH 600
#define WIN_HEIGHT 800
#define BLOCK_SIZE 50

// definitons 
typedef enum TYPE {I, J, L, O, S, T, Z} Type;
typedef enum DIRECTION {UP, DOWN, RIGHT, LEFT} Direction;

// structs
typedef struct Block {
    int x;
    int y; 
    Direction direction;
    Type type;
    Rectangle rects[4];
    Color color; 
} Block; 

// helper definitions
void buildBlock(Block block, float x, float y);
void updateBlock(Block block, float deltaTime);
void drawBlock(Block block, float deltaTime);

int main(int argc, char const *argv[]) {

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Tetris");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    return 0;
}

void buildBlock(Block block, float x, float y) {
    // TOOD: For each type of tetris block - build blocks in the correct position, relative to x, y
    block.x = x;
    block.y = y; 
    block.rects[0] = {x, y, BLOCK_SIZE, BLOCK_SIZE};

    if (block.type == I) {
        for (int i = 1; i < 4; i++) {
            block.rects[i] = {x + i * BLOCK_SIZE, y, BLOCK_SIZE, BLOCK_SIZE};
        }
    }
}

void updateBlock(Block block, float deltaTime) { 
    // TODO: Move blocks down, if they hit the bottom, add the rects to the rect grid, check for complete lines, and destroy the block

}

void drawBlock(Block block, float deltaTime) {
    // TODO: Draw blocks

}