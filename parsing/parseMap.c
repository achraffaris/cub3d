/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:01:46 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/07 12:05:39 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    check_borderline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && line[i] != '#')
            error_printer("A wall is not closed!!");
        i++;
    }
}

char    *create_map(char *map, char *line)
{
    char    *join;

    join = ft_strjoin(map, line);
    //free (map);
    return (join);
}

void    check_player(char *map, game_t **g)
{
    int i = 0;
    game_t  *aux = *g;

    while (map[i])
    {
        if (map[i] == 'N')
            aux->player_direction = 13;
        if (map[i] == 'W')
            aux->player_direction = 0;
        if (map[i] == 'S')
            aux->player_direction = 1;
        if (map[i] == 'E')
            aux->player_direction = 2;
        i++;
    }
    if (aux->player_direction == -1)
        error_printer("recheck player position!!");
}

char    **fill_in_map(char *map, int map_height, int map_width)
{
    char    **maps;
    int     i = 0;
    int     j;
    int     k = 0;

    maps = malloc(sizeof(char *) * (map_height + 1));
    while (i < map_height)
    {
        maps[i] = malloc(sizeof(char) * (map_width + 1));
        j = 0;
        while (map[k] && map[k] != 13)
        {
            maps[i][j] = map[k];
            k++;
            j++;
        }
        while (j < (map_width))
            maps[i][j++] = '#';
        maps[i][j] = '\0';
        k++;
        i++;
    }
    maps[i] = NULL;
    return (maps);
}

void    check_game_paths(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'E')
            {
                if (j == 0 || j == (width - 1))
                    error_printer("unvalid map!!");
                else
                {
                    if (i == 0 || i == (height - 1))
                        error_printer("unvalid map!!");
                    else
                    {
                        if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
                            error_printer("unvalid map");
                    }
                }
            }
            j++;
        }
        i++;
    }
}

void    parse_map(char *map, game_t **g)
{
    game_t  *aux;

    aux = *g;
    check_player(map, g);
    //printf("player view is =%d\n", aux->player_view);
    //printf("%s", map);
    aux->map = fill_in_map(map, aux->map_height, aux->map_width);
    // int i = 0;
    // while (aux->map[i])
    // {
    //     printf("%s====> %d", aux->map[i], ft_strlen(aux->map[i]));
    //     i++;
    // }
    check_game_paths(aux->map, aux->map_height, aux->map_width);
}