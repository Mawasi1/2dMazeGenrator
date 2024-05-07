#ifndef SAVE_MAZE_COMMAND_H
#define SAVE_MAZE_COMMAND_H

#include "command.h"
#include "mazeManager.h"
#include "mazeCompression.h"
#include "maze2d.h" 
#include <sstream>

class SaveMazeCommand : public Command {
private:
    MazeManager& mazeManager;
    MazeCompression mazeCompression;

public:
    SaveMazeCommand(MazeManager& mazeManager) : mazeManager(mazeManager) {}

    virtual void execute(const std::string& params) override {
        std::istringstream iss(params);
        std::string mazeName, fileName;
        iss >> mazeName >> fileName;

        try {
            Maze2D maze = mazeManager.getMaze(mazeName);
            mazeCompression.saveMaze(maze, fileName);
            std::cout << "Maze " << mazeName << " saved to " << fileName << ".\n";
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif
