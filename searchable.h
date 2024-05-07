#ifndef SEARCHABLE_H
#define SEARCHABLE_H

#include "state.h"

class Searchable {
public:
    virtual ~Searchable() = default; 

    virtual State* getStartPositionState() const = 0;

    virtual State* getGoalPositionState() const = 0;

    virtual std::vector<State*> getAllPossibleMovesStates(const State* state) const = 0;
};


#endif