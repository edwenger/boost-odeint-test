#include "Antibody.h"


const double Antibody::TWENTY_DAY_DECAY_CONSTANT = 0.05;
const double Antibody::B_CELL_PROLIFERATION_THRESHOLD = 0.4;
const double Antibody::B_CELL_PROLIFERATION_CONSTANT = 0.33;
const double Antibody::ANTIBODY_RELEASE_THRESHOLD = 0.3;
const double Antibody::ANTIBODY_RELEASE_FACTOR = 4;


double Antibody::threshold_function(double threshold, double variable)
{
    if (variable <= 0)
        return 0;

    return variable / (threshold + variable);
}

Antibody::Antibody(const double capacity_growth_rate_,
                   const double stimulation_c50_,
                   const double min_adapted_response_,
                   const double memory_level_,
                   const double kill_rate_)
    : capacity_growth_rate(capacity_growth_rate_)
    , stimulation_c50(stimulation_c50_)
    , min_adapted_response(min_adapted_response_)
    , memory_level(memory_level_)
    , kill_rate(kill_rate_)
    , hyperimmune_decay_rate(-log((0.4 - memory_level_) / (1 - memory_level_)) / 120.0)
{
}

void Antibody::operator() (const state_type &x, state_type &dxdt, double t)
{

    double antigen = x[State::ANTIGEN];
    double capacity = x[State::CAPACITY];
    double antibody = x[State::ANTIBODY];

    /*** Antigen concentration ***/
    // NB: merozoites_per_schizont as a discrete event every 48h

    dxdt[State::ANTIGEN] = -kill_rate * antibody * antigen;

    /*** Antibody capacity ***/

    double capacity_decay = hyperimmune_decay_rate * (capacity - memory_level);

    double capacity_increase = 0;
    if (capacity <= B_CELL_PROLIFERATION_THRESHOLD)
    {
        double stimulation = threshold_function(
            stimulation_c50,
            antigen + min_adapted_response*stimulation_c50);

        capacity_increase = capacity_growth_rate * (1-capacity) * stimulation;
    }
    else
    {
        capacity_increase = (1-capacity) * B_CELL_PROLIFERATION_CONSTANT;
    }

    dxdt[State::CAPACITY] = capacity_increase - capacity_decay;

    /*** Antibody concentration ***/

    double antibody_decay = TWENTY_DAY_DECAY_CONSTANT * antibody;

    double antibody_increase = 0;
    if (capacity > ANTIBODY_RELEASE_THRESHOLD)
        antibody_increase = (capacity - antibody) * ANTIBODY_RELEASE_FACTOR;

    dxdt[State::ANTIBODY] = antibody_increase - antibody_decay;

}
