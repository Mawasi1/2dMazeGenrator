#ifndef MY_MAZE2D_GENERATOR_H
#define MY_MAZE2D_GENERATOR_H

#include "abstractMaze2dGenerator.h"
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdlib> // for std::rand and std::srand
#include <ctime>   // for std::time

class MyMaze2DGenerator : public AbstractMaze2DGenerator
{
public:
    virtual Maze2D generate(const std::string &mazeName, int rows, int cols) const override
    {
        Maze2D maze(mazeName, rows, cols);

        // Fill the maze with walls
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                maze.setCell(i, j, '#');
            }
        }

        // Stack to hold the cells to visit
        std::stack<std::pair<int, int>> stack;

        // Start from a random cell
        std::srand(std::time(0));
        int startRow = std::rand() % rows;
        int startCol = std::rand() % cols;
        stack.push({startRow, startCol});
        maze.setCell(startRow, startCol, ' ');

        // DFS algorithm
        while (!stack.empty())
        {
            std::pair<int, int> currentCell = stack.top();
            stack.pop();

            int row = currentCell.first;
            int col = currentCell.second;

            // Check for valid neighbors
            std::vector<std::pair<int, int>> neighbors;
            for (int dr = -2; dr <= 2; dr += 4)
            {
                for (int dc = -2; dc <= 2; dc += 4)
                {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze.getCell(newRow, newCol) == '#' && maze.getCell(row + dr/2, col + dc/2) == '#')
                    {
                        neighbors.push_back({newRow, newCol});
                    }
                }
            }

            // Shuffle the neighbors to ensure a random path
            std::random_shuffle(neighbors.begin(), neighbors.end());

            // Carve paths to neighbors
            for (const auto& neighbor : neighbors)
            {
                int newRow = neighbor.first;
                int newCol = neighbor.second;
                if (maze.getCell(newRow, newCol) == '#')
                {
                    maze.setCell(newRow, newCol, ' ');
                    maze.setCell(row + (newRow - row) / 2, col + (newCol - col) / 2, ' ');
                    stack.push({newRow, newCol});
                }
            }
        }

        // Set start and goal positions
        maze.setStartPosition(startRow, startCol);
        int goalRow, goalCol;
        do
        {
            goalRow = std::rand() % rows;
            goalCol = std::rand() % cols;
        } while (maze.getCell(goalRow, goalCol) == '#' || (goalRow == startRow && goalCol == startCol));
        maze.setGoalPosition(goalRow, goalCol);

        return maze;
    }
};


#endif