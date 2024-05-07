#ifndef DISPLAY_COMMAND_H
#define DISPLAY_COMMAND_H

#include "command.h"
#include "maze2d.h"
#include <iostream>
#include <unordered_map>

class DisplayCommand : public Command {
private:
    MazeManager& mazeManager;

public:
    DisplayCommand(MazeManager& mazeManager) : mazeManager(mazeManager) {}

    virtual void execute(const std::string& params) override {
        try {
            Maze2D maze = mazeManager.getMaze(params);
            std::cout << "Displaying maze " << params << ":\n"; maze.display();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};


#endif
