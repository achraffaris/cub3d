#include "core.h"

double get_opposite(double angle, double hypotenuse)
{
    return (sin(angle) * hypotenuse);
}

double get_adjacent(double angle, double hypotenuse)
{
    return (cos(angle) * hypotenuse);
}

double degree_to_rad(double degree)
{
    return (degree * (M_PI / 180));
}