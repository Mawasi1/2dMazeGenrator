#ifndef TEST_MAZE2D_GENERATOR_H
#define TEST_MAZE2D_GENERATOR_H

#include "interfaceMaze2dGenerator.h"
#include "abstractMaze2dGenerator.h"
#include "simpleMaze2dGenerator.h"
#include "myMaze2dGenerator.h"
#include <iostream>
#include <vector>

class TestMazeGenerator {
public:
    TestMazeGenerator() {}

    void testMazeGenerator(Maze2DGenerator& mg) {
        // prints the time it takes the algorithm to run
        std::cout << mg.measureAlgorithmTime("MyMaze", 12, 12) << " ms\n";

        // generate another 2d maze
        Maze2D maze = mg.generate("MyMaze", 12, 12);

        // get the maze entrance
        std::pair<int, int> p = maze.getStartPosition();

        // print the position format (x, y)
        std::cout << "(" << p.first << ", " << p.second << ")\n";

        //get all the possible moves from a position
        std::vector<std::pair<int, int>> moves = maze.getPossibleMoves(p);
        for (const auto& move : moves) {
            std::cout << "(" << move.first << ", " << move.second << ")\n";
        }

        // print the goal position
        std::cout << maze.getGoalPosition().first << ", " << maze.getGoalPosition().second << "\n";
        std::cout << maze << "\n";

        std::cout << "------------------------------------" << std::endl;

    }
};

#endif


