#include "../raylib/src/raylib.h"
#include "../inc/npuzzle.hpp"
#include <unistd.h>               // for linux 

// render the board base on the number of square and them size
void render_board(int size)
{
    // select brown color and clear the board with this color
    Color background =  Color{205, 127, 50, 255};
    ClearBackground(background);
    Color lineColor =  Color{0, 0, 0, 255};

    // Draw grid of Board size + 1 ^ 2
    int line = SCREEN_HEIGHT;
    int offset = SCREEN_HEIGHT / size;
    for (int x = 0, i = 0; i < size; x += offset, i++)
    {
        DrawLine(x, 0, x, line, lineColor);
        DrawLine(0, x,line, x , lineColor);
    }
}

void render_puzzle(vector2d& puzzle)
{
    int size = puzzle.size();
    render_board(size);

    int line = SCREEN_HEIGHT;
    int offset = SCREEN_HEIGHT / size;
    int font_size = 50;
    int margin = (offset - font_size) / 2;
    int value = 0;
    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            value = puzzle[y][x];
            DrawText(std::to_string(puzzle[x][y]).c_str(), y*offset + margin, x*offset + margin, 50, LIGHTGRAY);
        }
    }
}

void    graphical_render(node& result){
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Result of A*");
    while (!WindowShouldClose())
    {
            for (int i = 0; i < (int)result.parent.size(); i++){
                BeginDrawing();
                render_puzzle(result.parent[i]);
                sleep(1);
                EndDrawing();
            }
             BeginDrawing();
                render_puzzle(result.puzzle);
            EndDrawing();
            sleep(5);
            break ;
    }

    CloseWindow();
}