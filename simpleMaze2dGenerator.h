#ifndef SIMPLE_MAZE2D_GENERATOR_H
#define SIMPLE_MAZE2D_GENERATOR_H

#include "abstractMaze2dGenerator.h"
#include <random>

class SimpleMaze2DGenerator : public AbstractMaze2DGenerator {
public:
    // Implementation of the generate method
    virtual Maze2D generate(const std::string& mazeName, int rows, int cols) const override {
        // Create a Maze2D object
        Maze2D maze(mazeName, rows, cols);

        // Randomly place walls in the maze
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Randomly decide whether to place a wall or an open path
                char cell = dis(gen) == 0 ? ' ' : '#';
                maze.setCell(i, j, cell);
            }
        }

        // Randomly set the start and goal positions
        std::uniform_int_distribution<> rowDist(0, rows - 1);
        std::uniform_int_distribution<> colDist(0, cols - 1);
        maze.setStartPosition(rowDist(gen), colDist(gen));
        maze.setGoalPosition(rowDist(gen), colDist(gen));

        // Ensure that the start and goal positions are open paths
        maze.setCell(maze.getStartPosition().first, maze.getStartPosition().second, ' ');
        maze.setCell(maze.getGoalPosition().first, maze.getGoalPosition().second, ' ');

        return maze;
    }
};


#endif