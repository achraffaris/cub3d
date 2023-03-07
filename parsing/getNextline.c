/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:07:51 by fchanane          #+#    #+#             */
/*   Updated: 2023/02/22 02:07:52 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	search(char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	while (i < j && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*restart(char **stock)
{
	char	*temp;

	if (*stock != NULL && **stock != '\0')
	{
		temp = *stock;
		*stock = NULL;
		return (temp);
	}
	else
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
}

char	*create_line(char **stock)
{
	char	*line;
	char	*tmp;
	int		i;

	i = search(*stock, '\n');
	tmp = *stock;
	line = ft_substr(*stock, 0, i + 1);
	*stock = ft_substr(*stock, i + 1, ft_strlen(*stock));
	free(tmp);
	return (line);
}

char	*stock_in(int fd, char *stock, char *rest, int rd)
{
	while (search(stock, '\n') == -1)
	{
		rd = read(fd, rest, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
			break ;
		rest[rd] = '\0';
		stock = ft_strjoin(stock, rest);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*line;
	char			*rest;
	int				rd;

	rd = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
	{
		stock = ft_strdup("");
		if (!stock)
			return (NULL);
	}
	rest = malloc (BUFFER_SIZE + 1);
	if (!rest)
		return (NULL);
	stock = stock_in(fd, stock, rest, rd);
	free (rest);
	if (search(stock, '\n') == -1)
		return (restart(&stock));
	line = create_line(&stock);
	return (line);
}
