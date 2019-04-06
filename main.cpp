#include <iostream>

#include <boost/numeric/odeint.hpp>

#include "model/Antibody.h"
#include "report/Reporter.h"

using namespace boost::numeric::odeint;

int main(int argc, char **argv)
{
    ReporterState reporter_state;
    Reporter reporter = Reporter(reporter_state);  // containers for times and states

    state_type x = {1e5 , 0 , 0};  // initial conditions

    Antibody antibody = Antibody();  // ODE model and params

    size_t steps = integrate(antibody, x, 0.0, 30.0, 1.0/24, reporter);

    reporter_state.Write(steps);
}
