/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:49:12 by bwisniew          #+#    #+#             */
/*   Updated: 2024/05/06 18:56:42 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

static bool is_null(void *buffer, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)buffer)[i] != 0)
			return (false);
		i++;
	}
	return (true);
}

size_t ft_arrlen(void *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (!is_null(arr + i * len, len))
		i++;
	return (i);
}