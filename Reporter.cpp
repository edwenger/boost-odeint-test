#include <iostream>

#include "Reporter.h"

void ReporterState::Append(const state_type &x, double t)
{
    m_states.push_back(x);
    m_times.push_back(t);
}

void ReporterState::Write(size_t steps)
{
    for( size_t i=0; i<=steps; i++ )
    {
        std::cout << m_times[i] << '\t'
                  << m_states[i][0] << '\t'
                  << m_states[i][1] << '\n';
    }
}


Reporter::Reporter(ReporterState& reporter_state)
    : m_reporter_state(reporter_state)
{

}

void Reporter::operator()(const state_type &x, double t)
{
    m_reporter_state.Append(x, t);
}
