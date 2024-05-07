#ifndef DEMO_H
#define DEMO_H

#include "maze2d.h"
#include "myMaze2DGenerator.h"
#include "BFS.h"
#include "aStar.h"
#include "maze2dSearchable.h"
#include <iostream>

class Demo
{
public:
    void run()
    {
        // 1. Create a maze2d with MyMaze2DGenerator
        MyMaze2DGenerator generator;
        Maze2D maze = generator.generate("MyMaze", 10, 10); // Example size 10x10

        // 2. Print it out
        std::cout << "Generated Maze:" << std::endl;
        maze.display();
        
        Maze2DSearchable mazeSearchable(&maze);

        // 3. Solve it with AStar
        AStar aStarSolver;
        std::cout << "Solution using A*:";
        Solution aStarSolution = aStarSolver.search(mazeSearchable);

        // 4. Solve it with BFS
        BFS bfsSolver;
        std::cout << "Solution using BFS:";
        Solution bfsSolution = bfsSolver.search(mazeSearchable);
    }
};

#endif