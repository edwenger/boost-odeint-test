#pragma once

#include "Types.h"

class Lorenz {

public:
    Lorenz(const double sigma_, const double R_, const double b_);

    void operator() (const state_type &x, state_type &dxdt, double t);

private:
    const double sigma;
    const double R;
    const double b;
};
