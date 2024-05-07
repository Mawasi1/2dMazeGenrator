#ifndef INTERFACE_MAZE2D_GENERATOR_H
#define INTERFACE_MAZE2D_GENERATOR_H

#include "maze2d.h"

class Maze2DGenerator {
public:
    // Virtual destructor to allow proper cleanup of derived classes
    virtual ~Maze2DGenerator() = default;

    // Pure virtual method to generate a Maze2D object
    virtual Maze2D generate(const std::string& mazeName,int rows, int cols) const = 0;

    // Pure virtual method to measure the amount of time it takes to generate a maze
    virtual double measureAlgorithmTime(const std::string& mazeName,int rows, int cols) const = 0;
};

#endif
