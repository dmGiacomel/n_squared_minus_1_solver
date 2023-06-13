#ifndef SOLVING_ALGORITHM_HPP
#define SOLVING_ALGORITHM_HPP
#include <unordered_set>
#include <list>
#include <../Matrix.hpp>
#include "../puzzle_n_minus_1.hpp"
#include "Heuristics.hpp"

class SolvingAlgorithm{
public:
    virtual std::list<moves> solve(const Puzzle& initial_state,
                                     const std::vector<Puzzle>& goal_states,
                                     const Heuristics* heuristic = nullptr) = 0;
};

#endif 