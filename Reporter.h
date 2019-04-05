#pragma once

#include <vector>

#include "Common.h"

class Reporter
{
public:
    Reporter(std::vector<state_type> &states, std::vector<double> &times);

    void operator()(const state_type &x, double t);

    void Write(size_t steps);

private:
    std::vector<state_type>& m_states;
    std::vector<double>& m_times;
};
