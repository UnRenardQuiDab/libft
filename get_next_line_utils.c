/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:02:37 by bwisniew          #+#    #+#             */
/*   Updated: 2023/11/27 19:06:56 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	gnl_buffer_size(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i])
		i++;
	return (i);
}

long long	gnl_get_n(char	*buffer)
{
	size_t	n;

	n = 0;
	while (n < BUFFER_SIZE && (buffer[n] != '\n' && buffer[n] != '\0'))
		n++;
	if (n < BUFFER_SIZE && buffer[n] == '\n')
		return (n + 1);
	if (n < BUFFER_SIZE && buffer[n] == '\0')
		return (n);
	else
		return (-1);
}

char	*gnl_reset_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;

	dst_length = 0;
	while (dst[dst_length] && dst_length < size)
		dst_length++;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size - dst_length == 0)
		return (dst_length + src_length);
	i = 0;
	while (src[i] && size - dst_length - i != 1)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}
