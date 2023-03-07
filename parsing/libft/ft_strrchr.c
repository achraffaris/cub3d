/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:35:29 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/05 20:35:31 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

char	*ft_strrchr(char *s, int c)
{
	int		a;
	char	*str;

	str = (char *)s;
	a = ft_strlen(s);
	while (a >= 0)
	{
		if (str[a] == (char)c)
			return (&str[a]);
		a--;
	}
	return (0);
}
