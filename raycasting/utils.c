#include "raycasting.h"

int is_in_wall(t_game *g, point_t p)
{
    int i;
    int j;

    i = ceil((double)p.y / MAP_CELL_SIZE) - 1;
    j = ceil((double)p.x / MAP_CELL_SIZE) - 1;
    if (i >= 0 && j >= 0 && g->map[i][j] == '1')
    {
        printf("cell  = %c \n", g->map[i][j]);
        return (1);
    }
        
    return (0);
}

double  get_min(double a, double b)
{
    if (a < b)
        return (a);
    return (b);
}

int     angle_x_direction(double angle)
{
    if (angle > degree_to_rad(90) || angle > degree_to_rad(270))
        return (RIGHT);
    return (LEFT);
}

int     angle_y_direction(double angle)
{
    if (angle < degree_to_rad(180) && angle > degree_to_rad(0))
        return (SUD);
    return (NORTH);
}

double  normalize_angle(double angle)
{
    angle = fmod(angle, degree_to_rad(360));
    if (angle < 0)
        angle = degree_to_rad(360) + angle;
    return (angle);
}