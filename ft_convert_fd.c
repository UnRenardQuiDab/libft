/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:49 by lcottet           #+#    #+#             */
/*   Updated: 2024/03/21 19:28:10 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_no_flag_fd(int fd, char c)
{
	if (ft_putchar_fd('%', fd) < 0)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	return (2);
}

int	ft_convert_fd(int fd, va_list args, char *str)
{
	int	count;

	if (*str == 'c')
		count = ft_putchar_fd(va_arg(args, int), fd);
	else if (*str == '%')
		count = ft_putchar_fd('%', fd);
	else if (*str == 's')
		count = ft_putstr_fd(va_arg(args, char *), fd);
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr_base_fd(va_arg(args, int), "0123456789", fd);
	else if (*str == 'u')
		count = ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", fd);
	else if (*str == 'x')
		count = ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789abcdef", fd);
	else if (*str == 'X')
		count = ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789ABCDEF", fd);
	else if (*str == 'p')
		count = ft_putptr_fd(va_arg(args, unsigned long long), fd);
	else if (*str == '\0')
		return (-1);
	else
		count = ft_no_flag_fd(fd, *str);
	return (count);
}
