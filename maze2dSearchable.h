#ifndef MAZE2D_SEARCHABLE_H
#define MAZE2D_SEARCHABLE_H

#include "searchable.h"
#include "maze2d.h"

class Maze2DSearchable : public Searchable {
private:
    Maze2D* m_maze;

public:
    Maze2DSearchable(Maze2D* maze) : m_maze(maze) {}

    virtual State* getStartPositionState() const override {
        return new State(m_maze->getStartPosition());
    }

    virtual State* getGoalPositionState() const override {
        return new State(m_maze->getGoalPosition());
    }

    virtual std::vector<State*> getAllPossibleMovesStates(const State* state) const override {
        std::vector<std::pair<int, int>> moves = m_maze->getPossibleMoves(state->getState());
        std::vector<State*> states;
        for (const auto& move : moves) {
            states.push_back(new State(move));
        }
        return states;
    }
};

#endif
