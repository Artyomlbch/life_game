#include "grid.hpp"

class Simulation
{
public:

    Simulation(int width, int height, int cellSize) : grid(width, height, cellSize), temporary_grid(width, height, cellSize), run(false) { }
    Simulation& operator=(Simulation &other);
    void Draw();
    void setCellValue(int row, int column, int value);
    int countLiveNeighbours(int row, int column);
    void Update();
    bool is_running() { return run; }
    void start() { run = true; }
    void stop() { run = false; }
    void clear_grid();
    void create_random();
    void toggleCell(int row, int column);

private:
    Grid grid;
    Grid temporary_grid;
    bool run;

};