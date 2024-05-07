#ifndef MAZE_MANAGER_H
#define MAZE_MANAGER_H

#include "maze2d.h"
#include "solution.h"
#include <unordered_map>

class MazeManager {
private:
    std::unordered_map<std::string, Maze2D> mazes;
    std::unordered_map<std::string, Solution> solutions; 

public:
    void addMaze(const std::string& name, const Maze2D& maze) {
        mazes.emplace(name, maze);
    }

    Maze2D getMaze(const std::string& name) const {
        auto it = mazes.find(name);
        if (it != mazes.end()) {
            return it->second;
        }
        throw std::runtime_error("Maze not found: " + name);
    }

    // Method to get a solution if it exists
    Solution getSolution(const std::string& name) const {
        auto it = solutions.find(name);
        if (it != solutions.end()) {
            return it->second;
        }
        return Solution(); // Return an empty solution if not found
    }

    // Method to add a solution to the cache
    void addSolution(const std::string& name, const Solution& solution) {
        solutions[name] = solution;
    }
};

#endif
