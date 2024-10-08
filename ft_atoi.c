/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:40:55 by bwisniew          #+#    #+#             */
/*   Updated: 2024/09/06 21:28:05 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

static long	ft_getnb(const char *nptr, char sign, size_t i)
{
	int	nb;

	nb = 0;
	while (ft_isdigit(nptr[i]))
	{
		if (nb * sign != (nb * sign * 10 + nptr[i] - 48) / 10)
		{
			errno = ERANGE;
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	char	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	nb = ft_getnb(nptr, sign, i);
	return ((int)(nb * sign));
}
