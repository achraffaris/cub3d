/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:55:44 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/07 12:05:39 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../parser.h"

int encode_color(int t, int r, int g, int b)
{
    int encoded_color;

    encoded_color = t << 24 | r << 16 | g << 8 | b;
    return (encoded_color);
}

int count_words(char **table)
{
    int i;

    i = 0;
    while (table[i])
        i++;
    return (i);
}

void    check_valid_number(char *color)
{
    int i;
    int number;

    i = 0;
    while (color[i])
    {
        if (color[i] < '0' || color[i] > '9')
            error_printer("Color parameters should be numbers!!");
        i++;
    }
    number = ft_atoi(color);
    if (number < 0 || number > 255)
        error_printer("Unvalid range of number");
}

void    check_numbers(char **colors)
{
    int i;

    i = 0;
    while (colors[i])
    {
        check_valid_number(colors[i]);
        i++;
    }
}

int check_color(char **colors)
{
    int color;

    if (count_words(colors) != 3)
        error_printer("unvalid parameters!!");
    check_numbers(colors);
    color = encode_color(0, ft_atoi(colors[0]), ft_atoi(colors[1]), ft_atoi(colors[2]));
    return (color);
}

void    colors_parameters(char *content, game_t **g)
{
    int     i;
    int     color;
    char    **colors;
    game_t  *aux;

    i = 1;
    aux = *g;
    if ((content[0] == 'F' && aux->floor_color > -1) || (content[0] == 'C' && aux->ceiling_color > -1))
        error_printer("This color is already stored!!");
    while (content[i] && (content[i] == ' ' || content[i] == '\t'))
        i++;
    if (!content[i])
        error_printer("Color has no parameters!!");// handle leaks
    colors = ft_split(&content[i], ',');
    color = check_color(colors);
    if (content[0] == 'F' )
        aux->floor_color = color;
    if (content[0] == 'C')
        aux->ceiling_color = color;
}
