// mazeSizeCommand.h
#ifndef MAZE_SIZE_COMMAND_H
#define MAZE_SIZE_COMMAND_H

#include "command.h"
#include "mazeManager.h"

class MazeSizeCommand : public Command
{
private:
    MazeManager &mazeManager;

public:
    MazeSizeCommand(MazeManager &manager) : mazeManager(manager) {}
    virtual void execute(const std::string &params) override
    {
        try
        {
            Maze2D maze = mazeManager.getMaze(params);
            size_t sizeInBytes = maze.getSizeInBytes();
            std::cout << "Size of maze '" << params << "' in bytes: " << sizeInBytes << "\n";
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Maze with name '" << params << "' not found.\n";
        }
    }
};

#endif
