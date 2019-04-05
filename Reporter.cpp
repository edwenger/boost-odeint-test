#include <iostream>

#include "Reporter.h"

Reporter::Reporter(std::vector<state_type> &states, std::vector<double> &times)
    : m_states(states)
    , m_times(times)
{

}

void Reporter::operator()(const state_type &x, double t)
{
    m_states.push_back(x);
    m_times.push_back(t);
}

void Reporter::Write(size_t steps)
{
    for( size_t i=0; i<=steps; i++ )
    {
        std::cout << m_times[i] << '\t' << m_states[i][0] << '\t' << m_states[i][1] << '\n';
    }
}
