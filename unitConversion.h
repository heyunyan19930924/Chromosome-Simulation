#pragma once

//---------------------------------------------------------------------
// Simple unit conversions

inline double meters_to_microns(double meters) { return meters * 1e6; }
inline double microns_to_meters(double microns) { return microns * 1e-6; }
inline double microns_to_nanometers(double microns) { return microns * 1e3; }
inline double meters_to_nanometers(double meters) { return meters * 1e9; }
inline double nanometers_to_meters(double nanometers) { return nanometers * 1e-9; }

inline double seconds_to_nanoseconds(double seconds) { return seconds * 1e9; }
inline double nanoseconds_to_seconds(double nanoseconds) { return nanoseconds * 1e-9; }

inline double Pascal_to_gigaPascal(double Pascal) { return Pascal * 1e-9; }
inline double gigaPascal_to_Pascal(double gigaPascal) { return gigaPascal * 1e9; }

inline double Celsius_to_Kelvin(double Celsius) { return Celsius + 273.15; }
inline double Kelvin_to_Celsius(double Kelvin) { return Kelvin - 273.15; }

inline double Poise_to_centiPoise(double Poise) { return Poise * 1e2; }
inline double centiPoise_to_Poise(double centiPoise) { return centiPoise * 1e-2; }
inline double Poise_to_Pascal_seconds(double Poise) { return Poise * 1e-1; }
inline double Pascal_seconds_to_Poise(double Pascal_seconds) { return Pascal_seconds * 1e1; }
inline double centiPoise_to_Pascal_seconds(double centiPoise) {
                   return Poise_to_Pascal_seconds(centiPoise_to_Poise(centiPoise));
              }
inline double Pascal_seconds_to_centiPoise(double Pascal_seconds) {
                   return Poise_to_centiPoise(Pascal_seconds_to_Poise(Pascal_seconds));
              }

//---------------------------------------------------------------------
// Constants used to compute conversions below.
const double Avagadro_number = 6e23;
const double dna_mass_per_bp_in_Daltons = 610;
const double dna_mass_per_bp_in_kg = dna_mass_per_bp_in_Daltons / Avagadro_number;
const double Boltzmann_constant = 1.3806488e-23;

//---------------------------------------------------------------------
// More complex conversions needed to go from units familiar to biologists
// to units needed internally by the simulation program.

// Compute the mass of a specified length of B-form DNA in base pairs, and in kg
inline double dna_mass_in_bp(double segment_length_meters) {
    return segment_length_meters / ( 0.3 * 1e-9);
}
inline double dna_mass_in_kg(double segment_length_meters) {
    return dna_mass_in_bp(segment_length_meters) * dna_mass_per_bp_in_kg;
}

// Compute the tensile spring constant of a segment of DNA in Newtons/meter
extern double dna_tensile_spring_constant(double segment_length_meters
                                          , double dna_Youngs_modulus_Pa
                                          , double dna_radius_meters);

// Compute the force per unit bending angle (in Newtons/radian) for a segment of DNA
extern double dna_bending_rigidity(double dna_Youngs_modulus_Pa
                                          , double dna_radius_meters);
extern double dna_bending_spring_constant(double segment_length_meters
                                          , double dna_Youngs_modulus_Pa
                                          , double dna_radius_meters);

// Determine the expected distance to be traveled by the specified segments
// under Brownian motion over the timestep given.  Compute the constant force
// that would need to be applied over that same interval to move the segment
// against the specified viscosity that distance in the given time step.
// The effective radius is the area of a sphere that models the drag area.
extern double Brownian_force_equivalent(double effective_radius_meters
                             , double temperature_Kelvin
                             , double viscosity_Pascal_seconds);

// Determine the drag coefficient to use in the simulator for a given sphere radius
// and viscosity.
extern double mass_damping_equivalent(double viscosity_Pascal_seconds
				, double sphere_radius_meters);


