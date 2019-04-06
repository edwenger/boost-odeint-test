#include <iostream>
#include <fstream>

#include "Reporter.h"

void ReporterState::Append(const state_type &x, double t)
{
    m_states.push_back(x);
    m_times.push_back(t);
}

void ReporterState::Write(size_t steps)
{
    std::ofstream outfile;
    outfile.open("test/output.csv");
    for( size_t i=0; i<=steps; i++ )
    {
        std::cout << m_times[i] << '\t';
        outfile << m_times[i] << ',';
        for (size_t j=0; j< m_states[i].size(); j++)
        {
            std::cout << m_states[i][j] << '\t';
            outfile << m_states[i][j] << ',';
        }
        std::cout << std::endl;
        outfile << std::endl;
    }
    outfile.close();
}

Reporter::Reporter(ReporterState& reporter_state)
    : m_reporter_state(reporter_state)
{

}

void Reporter::operator()(const state_type &x, double t)
{
    m_reporter_state.Append(x, t);
}
