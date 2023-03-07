/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primaryChecks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:10:49 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/02 19:10:51 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void    ext_check(char *ext)
{
    if (!ext)
        error_printer(EXT_EMPTY);
    if (ft_strcmp(ext, ".cub") || ft_strlen(ext) != 4)
        error_printer(EXT_ERR);
}

void    arg_check(int ac, char *av)
{
    char    *ext;

    if (ac != 2)
        error_printer(ARG_ERR);
    if (!ft_strcmp(av, ".cub"))
        error_printer(AV_ERR);
    ext = ft_strchr(av, '.');
    ext_check(ext);
}

int file_check(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);
    if (fd < 0)
        error_printer(FILE_ERR);
    msg_printer("\33[0;32m********** Passed the first check!! **********\33[0m\n");
    return (fd);
}

int primary_checks(int ac, char *av)
{
    arg_check(ac, av);
    return (file_check(av));
}
