#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <memory>
#include <algorithm>
#include "state.h"

class Solution
{
private:
    std::vector<std::unique_ptr<State>> path;

public:
    // Constructor
    Solution() {}

    Solution(const Solution &other)
    {
        for (const auto &state : other.path)
        {
            path.push_back(std::make_unique<State>(*state));
        }
    }

    // Copy assignment operator (using copy semantics)
    Solution &operator=(const Solution &other)
    {
        if (this == &other)
            return *this;
        path.clear();
        for (const auto &state : other.path)
        {
            path.push_back(std::make_unique<State>(*state));
        }
        return *this;
    }

    // Method to add a state to the path
    void addState(std::unique_ptr<State> state)
    {
        path.push_back(std::move(state));
    }

    // Method to get the path (note: returning a vector of raw pointers for read-only access)
    std::vector<const State *> getPath() const
    {
        std::vector<const State *> rawPath;
        for (const auto &state : path)
        {
            rawPath.push_back(state.get());
        }
        return rawPath;
    }

    void print() const
    {
        for (const auto &state : path)
        {
            std::cout << "(" << state->getState().first << ", " << state->getState().second << ") -> ";
        }
        std::cout << "END\n";
    }

    void reversePath()
    {
        std::reverse(path.begin(), path.end());
    }
};

#endif
