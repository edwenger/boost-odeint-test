#include <iostream>

#include <boost/numeric/odeint.hpp>

#include "model/Lorenz.h"
#include "report/Reporter.h"

using namespace boost::numeric::odeint;

int main(int argc, char **argv)
{
    ReporterState reporter_state;
    Reporter reporter = Reporter(reporter_state);  // containers for times and states

    state_type x = {10.0 , 1.0 , 1.0};  // initial conditions

    Lorenz lorenz = Lorenz(10.0, 28.0, 8.0 / 3.0);  // ODE model and params

    size_t steps = integrate(lorenz, x, 0.0, 25.0, 0.1, reporter);

    reporter_state.Write(steps);
}
