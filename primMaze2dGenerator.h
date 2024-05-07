#ifndef MY_PRIM_MAZE2D_GENERATOR_H
#define MY_PRIM_MAZE2D_GENERATOR_H

#include "abstractMaze2dGenerator.h"
#include <vector>
#include <cstdlib> // for std::rand
#include <ctime>   // for std::time
#include <set>
#include <utility>

class PrimMaze2DGenerator : public AbstractMaze2DGenerator
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
        // Set to hold the frontier cells
        std::set<std::pair<int, int>> frontier;

        // Start from a random cell
        std::srand(std::time(0));
        int startRow = std::rand() % rows;
        int startCol = std::rand() % cols;
        maze.setCell(startRow, startCol, ' ');

        // Add the neighbors of the start cell to the frontier
        addNeighborsToFrontier(startRow, startCol, rows, cols, maze, frontier);

        // Prim's algorithm
        while (!frontier.empty())
        {
            // Choose a random frontier cell
            auto it = frontier.begin();
            std::advance(it, std::rand() % frontier.size());
            int row = it->first;
            int col = it->second;

            // Remove the current cell from the frontier
            frontier.erase(it);

            // Find a visited neighbor
            std::pair<int, int> neighbor = chooseVisitedNeighbor(row, col, maze);

            // If a visited neighbor is found, carve a path
            if (neighbor.first != -1 && neighbor.second != -1)
            {
                maze.setCell(row, col, ' ');
                maze.setCell((row + neighbor.first) / 2, (col + neighbor.second) / 2, ' ');
                addNeighborsToFrontier(row, col, maze.getRows(), maze.getCols(), maze, frontier);
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

        //maze.display();
        return maze;
    }

private:
    // Method to add the neighbors of a cell to the frontier
   void addNeighborsToFrontier(int row, int col, int rows, int cols, const Maze2D& maze, std::set<std::pair<int, int>>& frontier) const
{
    static const int directions[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

    for (const auto& dir : directions)
    {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        // Check if the neighbor is within bounds, is a wall, and has at least one visited neighbor
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze.getCell(newRow, newCol) == '#'
            && chooseVisitedNeighbor(newRow, newCol, maze).first != -1)
        {
            frontier.insert({newRow, newCol});
        }
    }
}


    // Method to choose a visited neighbor of a frontier cell
    std::pair<int, int> chooseVisitedNeighbor(int row, int col, const Maze2D &maze) const
    {
        static const int directions[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

        for (const auto &dir : directions)
        {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < maze.getRows() && newCol >= 0 && newCol < maze.getCols() && maze.getCell(newRow, newCol) == ' ')
            {
                return {newRow, newCol};
            }
        }

        return {-1, -1}; // Return an invalid neighbor if none are found (should not happen in a correct implementation)
    }
};

#endif
