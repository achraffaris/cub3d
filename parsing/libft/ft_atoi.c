/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:48:47 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/04 15:48:48 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../parser.h"

static int	ft_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static int	ft_check_sign(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = ft_whitespace(str);
	sign = 1;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((number * 10 + (str[i] - '0')) / 10 != number)
			return (ft_check_sign(sign));
		if (str[i] == '-' || str[i] == '+')
			return (number * sign);
		number = number * 10 + (str[i++] - 48);
	}
	return (number * sign);
}
