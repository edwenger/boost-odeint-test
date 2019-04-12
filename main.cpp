#include <iostream>

#include <boost/numeric/odeint.hpp>

#include "model/Antibody.h"
#include "report/Reporter.h"

using namespace boost::numeric::odeint;

int merozoites_per_schizont = 12;

int main(int argc, char **argv)
{
    ReporterState reporter_state;
    Reporter reporter = Reporter(reporter_state);  // containers for times and states

    state_type x = {1e-3, 0, 0};  // initial conditions

    Antibody *antibody = new Antibody();  // ODE model and params

    for (int days=0; days<210; days+=2) // 48h cycles
    {
        if (days == 180)
            x[0] = 1e-3;  // homologous reinfection

        if (x[0] < 2e-7)
            x[0] = 0;  // crudely discretize at 1 infected cell in 5 liters

        x[0] *= merozoites_per_schizont;

        size_t steps = integrate(
            *antibody, x,
            (double)days, (double)(days + 2), 2.0/24,
            reporter);
    }
    reporter_state.Write();
}
