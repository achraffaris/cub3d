/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:10:39 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

char    *compare_texture(char *content)
{
    if (!ft_strncmp(content, "NO", 2))
        return (ft_strdup("NO"));
    if (!ft_strncmp(content, "SO", 2))
        return (ft_strdup("SO"));
    if (!ft_strncmp(content, "WE", 2))
        return (ft_strdup("WE"));
    if (!ft_strncmp(content, "EA", 2))
        return (ft_strdup("EA"));
    return (NULL);
}

void    check_xpm(char *content)
{
    char    *ext;

    ext = ft_strrchr(content, '.');
    if (!ext || ft_strlen(ext) != 4)
        error_printer("Not a valid path extention");
    if (ft_strncmp(ext, ".xpm", 4))
        error_printer("Not a valid path extention");
}

void    check_valid_path(char *content)
{
    int fd;

    fd = open(content, O_RDONLY);
    if (fd < 0)
        error_printer("Path does not exist!!");
    close(fd);
    check_xpm(content);
}

void    assign_texture(char *texture, char *direct, t_game **g)
{
    t_game  *aux;

    aux = *g;
    if (!ft_strncmp(direct, "NO", 2))
    {
        if (aux->wall_nord)
            error_printer("Texture is already assigned!!");
        aux->wall_nord = ft_strdup(texture);
    }
    if (!ft_strncmp(direct, "SO", 2))
    {
        if (aux->wall_sud)
            error_printer("Texture is already assigned!!");
        aux->wall_sud = ft_strdup(texture);
    }
    if (!ft_strncmp(direct, "WE", 2))
    {
        if (aux->wall_west)
            error_printer("Texture is already assigned!!");
        aux->wall_west = ft_strdup(texture);
    }
    if (!ft_strncmp(direct, "EA", 2))
    {
        if (aux->wall_east)
            error_printer("Texture is already assigned!!");
        aux->wall_east = ft_strdup(texture);
    }
}

void    textures_parameters(char *content, t_game **g)
{
    int     i;
    char    *direct;

    direct = compare_texture(content);
    if (!direct)
        error_printer("Texture direction is not valid!!");
    i = 2;
    while (content[i] && (content[i] == ' ' || content[i] == '\t'))
        i++;
    if (!content[i] || (i == 2))
        error_printer("Texture has no path!!");
    check_valid_path(&content[i]);
    //printf("%s\n", direct);
    assign_texture(&content[i], direct, g);
}
