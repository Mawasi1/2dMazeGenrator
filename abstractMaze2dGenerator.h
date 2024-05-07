#ifndef ABSTRACT_MAZE2D_GENERATOR_H
#define ABSTRACT_MAZE2D_GENERATOR_H

#include "interfaceMaze2dGenerator.h"
#include <chrono> // for measuring time

class AbstractMaze2DGenerator : public Maze2DGenerator {
public:
    // Virtual destructor
    virtual ~AbstractMaze2DGenerator() = default;

    // Pure virtual method to generate a Maze2D object
    virtual Maze2D generate(const std::string& mazeName,int rows, int cols) const = 0;

    // Method to measure the amount of time it takes to generate a maze
    virtual double measureAlgorithmTime(const std::string& mazeName,int rows, int cols) const override {
        // Step 1: Measure system time before generating the maze
        auto start = std::chrono::high_resolution_clock::now();

        // Step 2: Generate the maze (calls the pure virtual generate method)
        generate(mazeName,rows, cols);

        // Step 3: Measure system time again and calculate the difference
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        // Return the time taken in seconds
        return elapsed.count();
    }
};


#endif