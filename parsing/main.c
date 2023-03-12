/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:14:27 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


int main(int ac, char **av)
{
    int     fd;
    t_game  *g;

    fd = primary_checks(ac, av[1]);
    g = malloc(sizeof(t_game));
    init_config_data(&g);
    parse_file(fd, &g);
}
