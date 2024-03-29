#include <vector>

class Grid
{
public:

    Grid(int width, int height, int cellSize) : rows(height / cellSize), columns(height / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {}
    void Draw();
    void setValue(int row, int column, const int value);
    bool isValidCoords(int row, int column);
    int getValue(int row, int column);
    int getRows() { return rows; }
    int getColumns() { return columns; }
    void fill_random();
    void clear();
    void toggle_cell(int row, int column);

private:

    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;

};