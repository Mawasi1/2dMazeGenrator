#include "maze2d.h"
#include <iostream>

// Constructor to initialize the maze with given dimensions
Maze2D::Maze2D(const std::string &mazeName, int rows, int cols)
    : name(mazeName), rows(rows), cols(cols)
{
    grid = new char *[rows];
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = ' '; // Initialize with open paths
        }
    }

}

Maze2D::Maze2D(const std::vector<char> &data)
{
    // Extract the dimensions, start, and goal positions
    rows = static_cast<int>(data[0]);
    cols = static_cast<int>(data[1]);
    startPosition = {static_cast<int>(data[2]), static_cast<int>(data[3])};
    goalPosition = {static_cast<int>(data[4]), static_cast<int>(data[5])};

    // Allocate the grid
    grid = new char *[rows];
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new char[cols];
    }

    // Fill the grid with the maze content
    int index = 6; // Start index for the maze content in the data array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = data[index++];
        }
    }
}

// Destructor to clean up dynamically allocated memory
Maze2D::~Maze2D()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

// Setter for the start position
void Maze2D::setStartPosition(int row, int col)
{
    startPosition = {row, col};
}

// Setter for the goal position
void Maze2D::setGoalPosition(int row, int col)
{
    goalPosition = {row, col};
}

// Setter for individual cells
void Maze2D::setCell(int row, int col, char value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        grid[row][col] = value;
    }
}

// Getter for the maze name
std::string Maze2D::getName() const
{
    return name;
}

// Getters for the start and goal positions
std::pair<int, int> Maze2D::getStartPosition() const
{
    return startPosition;
}

std::pair<int, int> Maze2D::getGoalPosition() const
{
    return goalPosition;
}

std::vector<std::pair<int, int>> Maze2D::getPossibleMoves(std::pair<int, int> position) const
{
    std::vector<std::pair<int, int>> moves;
    int row = position.first;
    int col = position.second;

    // Check horizontal and vertical neighbors
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0)
                continue; // Skip the current cell

            int newRow = row + dr;
            int newCol = col + dc;

            // Check if the new position is within bounds and not a wall
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] != '#')
            {
                moves.push_back({newRow, newCol});
            }
        }
    }

    return moves;
}

// Method to display the maze
void Maze2D::display() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (startPosition.first == i && startPosition.second == j)
            {
                std::cout << 'S' << ' '; // Start position
            }
            else if (goalPosition.first == i && goalPosition.second == j)
            {
                std::cout << 'G' << ' '; // Goal position
            }
            else
            {
                std::cout << grid[i][j] << ' ';
            }
        }
        std::cout << '\n';
    }
}

std::vector<char> Maze2D::getData() const
{
    std::vector<char> data;

    // Add the dimensions of the maze
    data.push_back(static_cast<char>(rows));
    data.push_back(static_cast<char>(cols));

    // Add the start position
    data.push_back(static_cast<char>(startPosition.first));
    data.push_back(static_cast<char>(startPosition.second));

    // Add the goal position
    data.push_back(static_cast<char>(goalPosition.first));
    data.push_back(static_cast<char>(goalPosition.second));

    // Flatten the 2D grid into the one-dimensional data vector
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            data.push_back(grid[i][j]);
        }
    }

    return data;
}

std::ostream &operator<<(std::ostream &os, const Maze2D &maze)
{
    for (int row = 0; row < maze.rows; ++row)
    {
        for (int col = 0; col < maze.cols; ++col)
        {
            os << maze.grid[row][col] << ' ';
        }
        os << '\n';
    }

    return os;
}

Maze2D::Maze2D(const Maze2D &other)
    : name(other.name), rows(other.rows), cols(other.cols),
      startPosition(other.startPosition), goalPosition(other.goalPosition)
{
    grid = new char *[rows];
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = other.grid[i][j];
        }
    }
}

Maze2D &Maze2D::operator=(const Maze2D &other)
{
    if (this == &other)
        return *this; // Handle self-assignment

    // Free existing resources
    for (int i = 0; i < rows; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;

    // Copy data from other object
    name = other.name;
    rows = other.rows;
    cols = other.cols;
    startPosition = other.startPosition;
    goalPosition = other.goalPosition;

    grid = new char *[rows];
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = other.grid[i][j];
        }
    }

    return *this;
}

void Maze2D::setName(std::string name)
{
    this->name = name;
}

size_t Maze2D::getSizeInBytes() const
{
    size_t size = sizeof(rows) + sizeof(cols) + sizeof(name) + sizeof(startPosition) + sizeof(goalPosition);
    for (int i = 0; i < rows; ++i)
    {
        size += sizeof(char) * cols;
    }
    return size;
}

// Getter for the number of rows in the maze
int Maze2D::getRows() const
{
    return rows;
}

// Getter for the number of columns in the maze
int Maze2D::getCols() const
{
    return cols;
}
