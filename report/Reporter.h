#pragma once

#include <vector>

#include "model/Types.h"

struct ReporterState
{
    std::vector<state_type> m_states;
    std::vector<double> m_times;

    void Append(const state_type &x, double t);

    void Write(size_t steps);
};

class Reporter
{
public:
    Reporter(ReporterState& reporter_state);

    void operator()(const state_type &x, double t);

private:
    ReporterState& m_reporter_state;
};
