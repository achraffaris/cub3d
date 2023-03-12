#include "raycasting.h"

void    set_horizontal_start(t_game *g, double angle, point_t *pt)
{
    double opposite;
    double adjacent;

    opposite = 0;
    adjacent = 0;
    pt->y = (ceil((double)g->player->pos.y / MAP_CELL_SIZE) - 1) * MAP_CELL_SIZE;
    if (angle_y_direction(angle) == SUD)
        pt->y += MAP_CELL_SIZE;
    pt->y--;
    opposite = g->player->pos.y - pt->y;
    adjacent = opposite / tan(angle);
    if (angle_y_direction(angle) == RIGHT)
        pt->x = g->player->pos.x + adjacent;
    else
        pt->x = g->player->pos.x - adjacent;
}

void    set_horizontal_step(double angle, point_t *pt)
{
    int xsign;
    int ysign;

    ysign = 1;
    xsign = 1;
    if (angle_x_direction(angle) == LEFT)
        xsign = -1;
    if (angle_y_direction(angle) == NORTH)
        ysign = -1;
    pt->y = MAP_CELL_SIZE * ysign;
    pt->x = (MAP_CELL_SIZE / tan(angle));
}

double  find_horizontal_intersection(t_game *g, double angle)
{
    point_t start;
    point_t step;

    set_horizontal_start(g, angle, &start);
    set_horizontal_step(angle, &step);
    printf("startx = %d, starty = %d\n", start.x, start.y);
    printf("stepx = %d, stepy = %d\n", step.x, step.y);
    while (start.x <= g->win_width && start.y <= g->win_height)
    {
        if (is_in_wall(g, start))
            break ;
        start.x += step.x;
        start.y += step.y;
    }
    int adj = start.x - g->player->pos.x;
    if (start.x < g->player->pos.x)
        adj = g->player->pos.x - start.x;
    return (get_hypoteneuse(angle, adj));
}