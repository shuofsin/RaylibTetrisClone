#include "raylib.h"

#define WIN_WIDTH 600
#define WIN_HEIGHT 800
#define BLOCK_SIZE 50


typedef enum DIRECTION {UP, DOWN, RIGHT, LEFT} Direction;

typedef struct Block {
    int x_pos;
    int y_pos; 
} Block;

typedef struct Tetromino {
    Block blocks[4];
    Direction direction; 
} Tetromino;

typedef struct I {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (3 * BLOCK_SIZE), y_pos}};
    Color color = WHITE;
} I;

typedef struct O {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos, y_pos + (BLOCK_SIZE)}, {x_pos + (BLOCK_SIZE), y_pos + (BLOCK_SIZE)}};
    Color color = WHITE;
} O;

typedef struct T {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos + (BLOCK_SIZE)}};
    Color color = WHITE;
} T;

typedef struct J {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (3 * BLOCK_SIZE), y_pos}};
    Color color = WHITE;
} J;

typedef struct L {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (3 * BLOCK_SIZE), y_pos}};
    Color color = WHITE;
} L;

typedef struct S {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (3 * BLOCK_SIZE), y_pos}};
    Color color = WHITE;
} S;

typedef struct Z {
    int x_pos;
    int y_pos; 
    Direction direction = UP; 
    Block blocks[4] = {{x_pos, y_pos}, {x_pos + BLOCK_SIZE, y_pos}, {x_pos + (2 * BLOCK_SIZE), y_pos}, {x_pos + (3 * BLOCK_SIZE), y_pos}};
    Color color = WHITE;
} Z;


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