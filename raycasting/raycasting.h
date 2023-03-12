#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "../cub3d.h"

int     is_in_wall(t_game *g, point_t p);
double  find_horizontal_intersection(t_game *g, double angle);
double  find_vertical_intersection(t_game *g, double angle);

double  get_min(double a, double b);
int     angle_x_direction(double angle);

int     angle_y_direction(double angle);
double  normalize_angle(double angle);
double  cast_ray(t_game *g, double angle);


#endif