#include <iostream>
#include "raylib.h"
#include "simulation.hpp"

int main()
{
    Color grey = {29, 29, 29, 255};
    const int WINDOWS_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;
    const int CELL_SIZE = 25;
    int FPS = 25;
    int generation = 0;

    InitWindow(WINDOWS_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOWS_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while(!WindowShouldClose())
    { 
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mouse_position = GetMousePosition();
            int row = mouse_position.y / CELL_SIZE;
            int column = mouse_position.x / CELL_SIZE;
            simulation.toggleCell(row, column);
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.start();
            SetWindowTitle("Running...");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.stop();
            SetWindowTitle("Stopped.");
        }
        else if (IsKeyPressed(KEY_UP))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            FPS -= 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.create_random();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.clear_grid();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();
        simulation.is_running() ? DrawText(TextFormat("Generation: %d", generation++), 0, 0, 20, LIGHTGRAY) : DrawText(TextFormat("Generation: %d", generation), 0, 0, 20, LIGHTGRAY);
        EndDrawing();
    }

    return 0;
}