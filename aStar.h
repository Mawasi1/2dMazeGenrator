#ifndef ASTAR_H
#define ASTAR_H

#include "commonSearcher.h"
#include <iostream>
#include <cmath> // For sqrt function
#include <queue>

class AStar : public CommonSearcher
{
public:
    Solution search(Searchable& searchable) override
    {
        auto compare = [](const State* a, const State* b) {
            return a->getStepCost() > b->getStepCost();
        };

        std::priority_queue<State*, std::vector<State*>, decltype(compare)> open(compare);
        std::vector<State*> closed;

        State* startState = searchable.getStartPositionState();
        open.push(startState);

        while (!open.empty())
        {
            State* currentState = open.top();
            open.pop();

            if (*currentState == *searchable.getGoalPositionState())
            {
                Solution solution;
                State* pathState = currentState;
                while (pathState != nullptr)
                {
                    solution.addState(std::make_unique<State>(*pathState));
                    pathState = pathState->getParentState();
                }
               solution.reversePath();

                // Cleanup
                for (State* state : closed)
                {
                    delete state;
                }
                delete currentState;

                return solution;
            }

            std::vector<State*> possibleMoves = searchable.getAllPossibleMovesStates(currentState);
            for (State* nextState : possibleMoves)
            {
                double gCost = currentState->getStepCost() + distance(currentState->getState(), nextState->getState());
                double hCost = distance(nextState->getState(), searchable.getGoalPositionState()->getState());
                nextState->setStepCost(gCost + hCost);

                auto it = std::find_if(closed.begin(), closed.end(), [&nextState](const State* state) {
                    return *state == *nextState;
                });

                if (it == closed.end())
                {
                    nextState->setParentState(currentState);
                    open.push(nextState);
                }
                else
                {
                    delete nextState; // Delete if already in the closed list
                }
            }

            closed.push_back(currentState);
        }

        // Cleanup
        for (State* state : closed)
        {
            delete state;
        }

        return Solution(); // Return an empty solution if no path is found
    }

private:
    // Euclidean distance function
    double distance(const std::pair<int, int>& a, const std::pair<int, int>& b) const
    {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return std::sqrt(dx * dx + dy * dy);
    }
};



#endif