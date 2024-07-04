/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 12:30:21 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	traverse_str(unsigned char *str, va_list ap, int fd)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += format_str(&str, ap, fd);
		else
		{
			ft_putchar_fd(*str++, fd);
			count++;
		}
	}
	return (count);
}

int	ft_printf_fd(const char *format, va_list ap, int fd)
{
	int				count;
	unsigned char	*str;

	if (fd < 0)
		return (-1);
	str = (unsigned char *)format;
	count = traverse_str(str, ap, fd);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_printf_fd(format, ap, 1);
	va_end(ap);
	return (count);
}
