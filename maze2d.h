#ifndef MAZE2D_H
#define MAZE2D_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

class Maze2D
{
private:
    std::string name;
    int rows;    // Number of rows in the maze
    int cols;    // Number of columns in the maze
    char **grid; // 2D grid representing the maze, e.g., ' ' for open path, '#' for wall
    std::pair<int, int> startPosition;
    std::pair<int, int> goalPosition;

public:
    // Constructor to initialize the maze with given dimensions
    Maze2D(const std::string &mazeName, int rows, int cols);
    Maze2D(const std::vector<char> &data);
    Maze2D(const Maze2D &other);            // Copy constructor
    Maze2D &operator=(const Maze2D &other); // Assignment operator

    // Destructor to clean up dynamically allocated memory
    ~Maze2D();
    // Getter for the maze name
    std::string getName() const;

    std::pair<int, int> getStartPosition() const;
    std::pair<int, int> getGoalPosition() const;

    std::vector<std::pair<int, int>> getPossibleMoves(std::pair<int, int> position) const;

    void setStartPosition(int row, int col);

    void setGoalPosition(int row, int col);

    void setCell(int row, int col, char value);

    void setName(std::string maze);

    void display() const;

    char getCell(int row, int col) const
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            return grid[row][col];
        }
        return '\0'; // Return a null character if the position is out of bounds
    }

    std::vector<char> getData() const;
    int getRows() const;
    int getCols() const;

    friend std::ostream &operator<<(std::ostream &os, const Maze2D &maze);
    size_t getSizeInBytes() const;
};

#endif