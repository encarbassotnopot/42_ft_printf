/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/06 15:58:24 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	print_char(t_fmt *fmt, unsigned char arg, int fd)
{
	char	*out;
	int		len;

	out = ft_calloc(sizeof(char), 2);
	if (!out)
		return (0);
	out[0] = arg;
	pad_spaces(fmt, &out);
	len = ft_strlen(out);
	ft_putstr_fd(out, fd);
	free(out);
	return (len);
}

int	print_str(t_fmt *fmt, const char *arg, int fd)
{
	char	*out;
	int		len;

	if (!arg)
		out = ft_strdup("(null)");
	else
		out = ft_substr(arg, 0, fmt->precision);
	if (!out)
		return (0);
	pad_spaces(fmt, &out);
	len = ft_strlen(out);
	ft_putstr_fd(out, fd);
	free(out);
	return (len);
}

int	print_ptr(t_fmt *fmt, void *arg, int fd)
{
	char	*num;
	int		len;

	if (arg == 0)
		return (print_str(fmt, "(nil)", fd));
	fmt->precision = -1;
	fmt->alternate = '#';
	fmt->conversion = 'x';
	num = ft_sttoa_base((size_t)arg, "0123456789abcdef");
	pad_zeroes(fmt, &num);
	pad_spaces(fmt, &num);
	len = ft_strlen(num);
	ft_putstr_fd(num, fd);
	free(num);
	return (len);
}

int	print_int(t_fmt *fmt, int arg, int fd)
{
	char	*num;
	int		len;

	if (arg < 0)
	{
		fmt->sign = '-';
		arg = ~(arg - 1);
	}
	if (!(fmt->precision == 0 && arg == 0))
	{
		num = ft_utoa((unsigned int)arg);
		pad_zeroes(fmt, &num);
		add_sign(fmt, &num);
	}
	else
		num = ft_calloc(sizeof(char), 1);
	pad_spaces(fmt, &num);
	len = ft_strlen(num);
	ft_putstr_fd(num, fd);
	free(num);
	return (len);
}

int	print_unsigned(t_fmt *fmt, unsigned int arg, int fd)
{
	char	*num;
	int		len;

	if (!(fmt->precision == 0 && arg == 0))
	{
		num = get_nbr_base(arg, fmt->conversion);
		if (arg == 0)
			fmt->alternate = '\0';
		pad_zeroes(fmt, &num);
	}
	else
		num = ft_calloc(sizeof(char), 1);
	pad_spaces(fmt, &num);
	len = ft_strlen(num);
	ft_putstr_fd(num, fd);
	free(num);
	return (len);
}
