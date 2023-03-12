/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:41:35 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    raise_flag(int *flag, t_game **g)
{
    t_game  *aux;

    aux = *g;
    if (!aux->wall_east && !aux->wall_sud && !aux->wall_west && !aux->wall_nord)
    {
        if (aux->floor_color != -1 && aux->ceiling_color != -1)
            *flag = 1;
    }
}

void    check_empty_file(char *line, t_game **g)
{
    if (!line)
    {
        unvalid_game(g);
        error_printer(EMPTY_FILE);
    }
}

void    parse_file(int fd, t_game **g)
{
    char    *line;
    int     stopper;

    line = get_next_line(fd);
    stopper = 0;
    check_empty_file(line, g);
    while (line && (stopper < 6))
    {
        if (!empty_line(line))
        {
            parse_config(line, g);
            stopper++;
        }
        free(line);
        line = get_next_line(fd);
    }
    // aux = *g;
    // printf("%s\n", aux->wall_east);
    // printf("%s\n", aux->wall_sud);
    // printf("%s\n", aux->wall_west);
    // printf("%s\n", aux->wall_nord);
    // printf("%d\n", aux->floor_color);
    // printf("%d\n", aux->ceiling_color);
    if (line)
    {
        while (empty_line(line))// this to skip empty line between config and map
        {
            free(line);
            line = get_next_line(fd);
        }
    }
    t_game *aux;
    aux = *g;
    char    *map = ft_strdup("");
    if (line)
    {
        while (line)
        {
            if (ft_strlen(line) > aux->map_width)
                aux->map_width = ft_strlen(line);
            if (empty_line(line))
                error_printer(MAP_ERR);
            aux->map_height++;
            map = create_map(map, line);
            //msg_printer(line);
            free(line);
            line = get_next_line(fd);
        }
    }
    aux->map_width--;
    parse_map(map, g);
    //printf("lines =%d\ncolumns =%d\n%s", aux->map_height, aux->map_width, map);
}
