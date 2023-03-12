#include "raycasting.h"

double  cast_ray(t_game *g, double angle)
{
    //double  v_intersection;
    double  h_intersection;

    h_intersection = find_horizontal_intersection(g, angle);
    //v_intersection = find_vertical_intersection(g, angle);
    printf("h_intersection = %f\n", h_intersection);
    return (h_intersection);
}