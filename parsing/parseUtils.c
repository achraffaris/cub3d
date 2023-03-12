/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:58:59 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool    empty_line(char *line)
{
    int i;

    i = 0;

    while (line[i])
    {
        if (!(line[i] == '\n' || (line[i] >= 9 && line[i] <= 13) || line[i] == ' ' || line[i] == '\t'))
            return false;
        i++;
    }
    return true;
}

void    parse_config(char *line, t_game **g)
{
    int     start;
    int     end;
    char    *content;

    start = 0;
    while (line[start] == '\n' || (line[start] >= 9 && line[start] <= 13) || line[start] == ' ' || line[start] == '\t')
        start++;
    end = ft_strlen(line) - 1;
    while (line[end] == '\n' || (line[end] >= 9 && line[end] <= 13) || line[end] == ' ' || line[end] == '\t')
        end--;
    content = ft_substr(line, start, (end - start + 1));//has the line without whitespaces or \n
    if (content[0] == 'F' || content[0] == 'C')
        colors_parameters(content, g);
    if (content[0] == 'N' || content[0] == 'S' || content[0] == 'W' || content[0] == 'E')
        textures_parameters(content, g);
}
