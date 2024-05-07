#ifndef SOLVE_COMMAND_H
#define SOLVE_COMMAND_H

#include "command.h"
#include "mazeManager.h"
#include "searcher.h"
#include "BFS.h"
#include "AStar.h"
#include "maze2DSearchable.h"
#include <string>
#include <iostream>
#include <memory>
#include <sstream>

class SolveCommand : public Command {
private:
    MazeManager& mazeManager;

public:
    SolveCommand(MazeManager& manager) : mazeManager(manager) {}

    virtual void execute(const std::string& params) override {
        std::istringstream iss(params);
        std::string mazeName, algorithm;
        iss >> mazeName >> algorithm;

        // Check if a solution already exists in the cache
        Solution cachedSolution = mazeManager.getSolution(mazeName);
        if (!cachedSolution.getPath().empty()) {
            std::cout << "Cached solution found for maze: " << mazeName << "\n";
            cachedSolution.print();
            return;
        }

        Maze2D maze = mazeManager.getMaze(mazeName);
        Maze2DSearchable searchableMaze(&maze);

        std::unique_ptr<Searcher> searcher;
        if (algorithm == "bfs") {
            searcher = std::make_unique<BFS>();
        } else if (algorithm == "astar") {
            searcher = std::make_unique<AStar>();
        } else {
            std::cerr << "Unknown algorithm: " << algorithm << "\n";
            return;
        }

        Solution solution = searcher->search(searchableMaze);
        solution.print();

        // Store the solution in the cache
        mazeManager.addSolution(mazeName, solution);
    }
};

#endif
