#pragma once

#include <cmath>

#include "Types.h"

enum State { ANTIGEN, CAPACITY, ANTIBODY };

class Antibody {

private:
    static const double TWENTY_DAY_DECAY_CONSTANT;
    static const double B_CELL_PROLIFERATION_THRESHOLD;
    static const double B_CELL_PROLIFERATION_CONSTANT;
    static const double ANTIBODY_RELEASE_THRESHOLD;
    static const double ANTIBODY_RELEASE_FACTOR;

    static double threshold_function(double threshold, double variable);

public:
    Antibody(const double capacity_growth_rate_=0.09,
             const double stimulation_c50_=30,
             const double min_adapted_response_=0.05,
             const double memory_level_=0.34,
             const double kill_rate_=1.596);

    void operator() (const state_type &x, state_type &dxdt, double t);

private:
    const double capacity_growth_rate;
    const double stimulation_c50;
    const double min_adapted_response;
    const double memory_level;
    const double kill_rate;
    const double hyperimmune_decay_rate;
};
