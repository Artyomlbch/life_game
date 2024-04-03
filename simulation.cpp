#include "simulation.hpp"

Simulation& Simulation::operator=(Simulation &other)
{
    this->grid = other.grid;
    this->temporary_grid = other.temporary_grid;
    this->run = other.run;

    return *this;
}

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::setCellValue(int row, int column, int value)
{
    grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbours(int row, int column)
{
    int live_neighbours = 0;
    std::vector<std::pair<int, int>> neighboursSet = 
    {
        {-1, 0},    // above
        {1, 0},     // below
        {0, -1},    // left
        {0, 1},     // right
        {-1, -1},   // upper left
        {-1, 1},    // upper right
        {1, -1},    // lower right
        {1, 1}      // lower left   
    };

    for (const auto& offset : neighboursSet)
    {
        int neighbourRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighbourColumn =  (column + offset.second + grid.getColumns()) % grid.getColumns();
        live_neighbours += grid.getValue(neighbourRow, neighbourColumn);
    }
    return live_neighbours;
}

void Simulation::Update()
{
    if (is_running())
    {   
        for (int row = 0; row < grid.getRows(); ++row)
        {
            for (int column = 0; column < grid.getColumns(); ++column)
            {
                int live_neighbours = countLiveNeighbours(row, column);
                int cellValue = grid.getValue(row, column);

                if (cellValue)
                {
                    if (live_neighbours > 3 || live_neighbours < 2)
                    {
                        temporary_grid.setValue(row, column, 0);
                    }
                    else
                    {
                        temporary_grid.setValue(row, column, 1);
                    }
                }
                else
                {
                    if (live_neighbours == 3)
                    {
                        temporary_grid.setValue(row, column, 1);
                    }
                    else
                    {
                        temporary_grid.setValue(row, column, 0);
                    }
                }
            }
        }
        grid = temporary_grid;
    }
}

void Simulation::clear_grid()
{
    if (!is_running())
    {
        grid.clear();
    }
}

void Simulation::create_random()
{
    if (!is_running())
    {
        grid.fill_random();
    }
}

void Simulation::toggleCell(int row, int column)
{
    grid.toggle_cell(row, column);
}
