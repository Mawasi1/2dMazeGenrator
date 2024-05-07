#ifndef BFS_H
#define BFS_H

#include "commonSearcher.h"
#include <queue>
#include <algorithm>
#include <iostream>

class BFS : public CommonSearcher
{
public:
    Solution search(Searchable &searchable) override
    {
        std::queue<State *> queue;    // Queue for BFS
        std::vector<State *> visited; // Keep track of visited states

        std::unique_ptr<State> startState = std::make_unique<State>(*searchable.getStartPositionState());
        queue.push(startState.get());
        visited.push_back(startState.get());

        while (!queue.empty())
        {
            State *currentState = queue.front();
            queue.pop();

            // Print the current state's coordinates
            std::pair<int, int> coordinates = currentState->getState();
            std::cout << "Visiting node at (" << coordinates.first << ", " << coordinates.second << ")" << std::endl;

            // Check if the current state is the goal state
            if (*currentState == *searchable.getGoalPositionState())
            {
                // Construct the solution here
                Solution solution;
                State *pathState = currentState;
                while (pathState != nullptr)
                {
                    solution.addState(std::make_unique<State>(*pathState));
                    pathState = pathState->getParentState();
                }
                // std::reverse(solution.getPath().begin(), solution.getPath().end()); // Reverse the path
                // solution.print(); 
                return solution;
            }

            // Get all possible moves from the current state
            std::vector<State *> possibleMoves = searchable.getAllPossibleMovesStates(currentState);
            for (State *nextState : possibleMoves)
            {
                if (std::find(visited.begin(), visited.end(), nextState) == visited.end())
                {
                    nextState->setParentState(currentState); // Set the parent of the next state
                    queue.push(nextState);
                    visited.push_back(nextState);
                }
            }
        }

        // Return an empty solution if no path is found
        std::cout << "BFS solving algorithm called " << std::endl;
        return Solution();
    }
};

#endif
