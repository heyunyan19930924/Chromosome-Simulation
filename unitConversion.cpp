#include "unitConversion.h"
#include <math.h>

//---------------------------------------------------------------------
// Helper functions and constant

#ifndef	M_PI
const double M_PI = 2*acos(0.0);
#endif

static inline	double	sqr(double a) { return (a)*(a); }

//---------------------------------------------------------------------
// Functions declared in the header

double dna_tensile_spring_constant(double segment_length_meters,
                                          double dna_Youngs_modulus_Pa,
                                          double dna_radius_meters)
{
    return dna_Youngs_modulus_Pa
           * (M_PI * sqr(dna_radius_meters))
           / segment_length_meters;
}

double dna_bending_rigidity(double dna_Youngs_modulus_Pa
                                          , double dna_radius_meters)
{
    return ( dna_Youngs_modulus_Pa * M_PI * pow(dna_radius_meters, 4.0) )
            / 4.0;
}

double dna_bending_spring_constant(double segment_length_meters,
                                          double dna_Youngs_modulus_Pa,
                                          double dna_radius_meters)
{
    return 2 * dna_bending_rigidity( dna_Youngs_modulus_Pa, dna_radius_meters )
        / sqr(segment_length_meters);
}

double Brownian_force_equivalent(double effective_radius_meters
                             , double temperature_Kelvin
                             , double viscosity_Pascal_seconds)
{
    double kBT = 6 * M_PI * viscosity_Pascal_seconds * effective_radius_meters * temperature_Kelvin * Boltzmann_constant;
    return sqrt(2*kBT);
}

extern double mass_damping_equivalent(double viscosity_Pascal_seconds
                                , double sphere_radius_meters)
{
    double drag_coefficient = 6 * M_PI * viscosity_Pascal_seconds * sphere_radius_meters;
    return drag_coefficient;
}

