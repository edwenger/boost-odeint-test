#include <iostream>

#include <boost/numeric/odeint.hpp>

#include "Lorenz.h"
#include "Reporter.h"

using namespace boost::numeric::odeint;

int main(int argc, char **argv)
{
    std::vector<state_type> x_vec;
    std::vector<double> times;
    Reporter reporter = Reporter(x_vec, times);

    state_type x = {10.0 , 1.0 , 1.0}; // initial conditions

    Lorenz lorenz = Lorenz(10.0, 28.0, 8.0 / 3.0); // ODE model and params

    size_t steps = integrate(lorenz, x, 0.0, 25.0, 0.1, reporter);

    reporter.Write(steps);
}
