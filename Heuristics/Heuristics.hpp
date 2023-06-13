#ifndef HEURISTICS_HPP
#define Heuristics_HPP
#include "../puzzle_n_minus_1.hpp"
#include "../Matrix.hpp"

class Heuristics {
    virtual int evaluate (const Puzzle& puzzle, const std::set<Puzzle>& goal_states){};
};

#endif