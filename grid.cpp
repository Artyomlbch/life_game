#include "grid.hpp"
#include "raylib.h"

void Grid::Draw()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

bool Grid::isValidCoords(int row, int column)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        return true;
    }
    return false;
}

int Grid::getValue(int row, int column)
{
    if (isValidCoords(row, column));
    {
        return cells[row][column];
    }
    return 0;
}

void Grid::fill_random()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            int random_value = GetRandomValue(0, 4);
            cells[row][column] = (random_value == 4) ? 1 : 0;
        }
    }
}

void Grid::clear()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            cells[row][column] = 0;
        }
    }
}

void Grid::toggle_cell(int row, int column)
{
    cells[row][column] = (!cells[row][column]);
}

void Grid::setValue(int row, int column, const int value)
{
    if (isValidCoords(row, column))
    {
        cells[row][column] = value;
    }
}