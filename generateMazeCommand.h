#ifndef GENERATE_MAZE_COMMAND_H
#define GENERATE_MAZE_COMMAND_H

#include "command.h"
#include "maze2d.h"
#include "interfaceMaze2dGenerator.h"
#include "simpleMaze2dGenerator.h"
#include "primMaze2dGenerator.h"
#include "myMaze2dGenerator.h"
#include "mazeManager.h"
#include <iostream>
#include <sstream>

class GenerateMazeCommand : public Command
{
private:
    MazeManager &mazeManager;

public:
    GenerateMazeCommand(MazeManager &mazeManager) : mazeManager(mazeManager) {}
    virtual void execute(const std::string &params) override
    {
        std::istringstream iss(params);
        std::string name;
        int rows, cols;
        std::string method;
        iss >> name >> rows >> cols >> method;

        Maze2DGenerator *generator = nullptr;
        if (method == "simple")
        {
            generator = new SimpleMaze2DGenerator();
        }
        else if (method == "my")
        {
            generator = new MyMaze2DGenerator();
        }
        else if (method == "prim")
        {
            generator = new PrimMaze2DGenerator();
        }
        else
        {
            std::cerr << "Unknown generation method: " << method << std::endl;
            return;
        }

        Maze2D maze = generator->generate(name, rows, cols);
        std::cout << "Maze generated successfully:\n";
        maze.display();
        mazeManager.addMaze(name, maze);

        delete generator;
    }
};

#endif
