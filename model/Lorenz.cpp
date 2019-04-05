#include "Lorenz.h"

Lorenz::Lorenz(const double sigma_, const double R_, const double b_)
    : sigma(sigma_)
    , R(R_)
    , b(b_)
{

}

void Lorenz::operator() (const state_type &x, state_type &dxdt, double t)
{
    dxdt[0] = sigma * ( x[1] - x[0] );
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}
