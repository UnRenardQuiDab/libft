/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:58:25 by bwisniew          #+#    #+#             */
/*   Updated: 2024/05/07 13:54:07 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "libft.h"

static size_t	ft_strdigitlen_pow(const char *str)
{
	size_t	i;
	size_t	power;

	i = 0;
	power = 1;
	while (ft_isdigit(str[i]))
	{
		power *= 10;
		i++;
	}
	return (power);
}

static double	ft_getnb(const char *nptr, char sign, size_t i, bool is_decimal)
{
	double	nb;

	nb = 0.0f;
	while (ft_isdigit(nptr[i]))
	{
		if ((int)nb != (int)(nb * 10 + (nptr[i] - 48)) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	(void) is_decimal;
	if (nptr[i] != '.' || is_decimal)
		return (nb);
	return (nb + ft_getnb(nptr, 1, i + 1, true) \
		/ (double) ft_strdigitlen_pow(nptr + i + 1));
}

double	ft_atof(const char *nptr)
{
	size_t	i;
	char	sign;
	double	nb;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	nb = ft_getnb(nptr, sign, i, false);
	return ((double)(nb * sign));
}
