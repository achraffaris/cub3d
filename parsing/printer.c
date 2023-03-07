/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:19:52 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/02 00:19:54 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    msg_printer(char *msg)
{
    int i;

    i = 0;
    while (msg[i])
    {
        write(1, &msg[i], 1);
        i++;
    }
}

void    error_printer(char *err)
{
    msg_printer("ERROR!! : ");
    msg_printer(err);
    msg_printer("\n");
    exit(1);
}
