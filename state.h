#ifndef STATE_H
#define STATE_H

#include <utility>

class State {
private:
    std::pair<int, int> m_state;
    double stepCost; // Cost of moving to this state
    State* parentState; // Pointer to the previous state

public:
    // Constructor
    State(std::pair<int, int> state, double cost = 0, State* parent = nullptr)
        : m_state(state), stepCost(cost), parentState(parent) {}

    // Getters
    std::pair<int, int> getState() const { return m_state; }
    double getStepCost() const { return stepCost; }
    State* getParentState() const { return parentState; }

    // Setter for parent state
    void setParentState(State* parent) {
        parentState = parent;
    }

    void setStepCost(double cost) { stepCost = cost; }

    bool operator==(const State& other) const {
        return m_state == other.m_state;
    }

};

#endif
