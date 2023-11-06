/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:54:44 by bwisniew          #+#    #+#             */
/*   Updated: 2023/11/06 18:38:37 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(int c);
int	ft_memset(int c);
int	ft_bzero(int c);
int	ft_memcpy(int c);
int	ft_memmove(int c);
int	ft_strlcpy(int c);
int	ft_strlcat(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_strchr(int c);
int	ft_strrchr(int c);
int	ft_strncmp(int c);
int	ft_memchr(int c);
int	ft_memcmp(int c);
int	ft_strnstr(int c);
int	ft_atoi(int c);
int	ft_calloc(int c);
int	ft_strdup(int c);

#endif