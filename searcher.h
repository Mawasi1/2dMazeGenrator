#ifndef SEARCHER_H
#define SEARCHER_H

#include "solution.h"
#include "searchable.h"

class Searcher {
public:
    virtual ~Searcher() = default; 

    virtual Solution search(Searchable& searchable) = 0;

    virtual int getNumberOfNodesEvaluated() const = 0;
};

#endif
