/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaksHunter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:54:10 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/07 12:05:39 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    unvalid_game(game_t **g)
{
    game_t  *aux;

    aux = *g;
    if (aux->wall_east)
        free(aux->wall_east);
    if (aux->wall_sud)
        free(aux->wall_sud);
    if (aux->wall_west)
        free(aux->wall_west);
    if (aux->wall_nord)
        free(aux->wall_nord);
    free(*g);
}
