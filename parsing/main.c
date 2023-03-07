/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:14:27 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/07 12:05:39 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


int main(int ac, char **av)
{
    int     fd;
    game_t  *g;

    fd = primary_checks(ac, av[1]);
    g = malloc(sizeof(game_t));
    init_config_data(&g);
    parse_file(fd, &g);
}
