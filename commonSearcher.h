#ifndef COMMON_SEARCHER_H
#define COMMON_SEARCHER_H

#include "searcher.h"
#include <queue>

class CommonSearcher : public Searcher
{
private:
    int m_evaluatedNodes;                  // Number of evaluated nodes
    std::priority_queue<State> m_openList; // Priority queue of states

public:
    CommonSearcher() : m_evaluatedNodes(0) {}
    virtual Solution search(Searchable &searchable) = 0;

    // Method to get the number of nodes evaluated during the search
    virtual int getNumberOfNodesEvaluated() const { return m_evaluatedNodes; }

    // Method to pop the top state from the open list
   const State &popOpenList()
    {
        m_evaluatedNodes++; // Increment the number of evaluated nodes
        const State &topState = m_openList.top();
        return topState;
    }

    
};

#endif
