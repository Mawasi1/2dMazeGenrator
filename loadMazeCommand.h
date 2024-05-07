#ifndef LOAD_MAZE_COMMAND_H
#define LOAD_MAZE_COMMAND_H

#include "command.h"
#include "mazeManager.h"
#include "mazeCompression.h"
#include <sstream>

class LoadMazeCommand : public Command
{
private:
    MazeManager& mazeManager;
    MazeCompression mazeCompression;

public:
    LoadMazeCommand(MazeManager& manager) : mazeManager(manager) {}

    virtual void execute(const std::string& params) override
    {
        std::istringstream iss(params);
        std::string filename, mazeName;
        iss >> filename >> mazeName;

        Maze2D maze = mazeCompression.loadMaze(filename);
        maze.setName(mazeName);
        mazeManager.addMaze(mazeName, maze);

        std::cout << "Maze loaded successfully from " << filename << " and named " << mazeName << "!\n";
    }
};

#endif
