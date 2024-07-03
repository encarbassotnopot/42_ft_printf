/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 16:38:52 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "set_flag.h"
#include "custom_print.h"
#include <stdarg.h>
#include <stdlib.h>

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = calloc(1, sizeof(t_fmt));
	if (!fmt)
		return (NULL);
	return (fmt);
}

t_fmt	*parse_format(unsigned char *c)
{
	t_fmt				*fmt;
	const unsigned char	*orig = c;

	void (*set_flag[])(t_fmt *) = {set_hash, set_zero, set_minus, set_space,
		set_plus};
	fmt = init_fmt();
	if (!fmt)
		return (NULL);
	while (ft_strchr_idx("#0- +", *c) != -1)
		set_flag[get_flag_idx(*c++)](fmt);
	fmt->min_width = ft_raw_atoi_fwd(&c);
	if (*c++ == '.')
		fmt->precision = ft_raw_atoi_fwd(&c);
	if (ft_strchr_idx("cspdiuxX", *c) != -1)
	{
		fmt->conversion = c;
		fmt->len = c - orig;
		return (fmt);
	}
	else
	{
		free(fmt);
		return (NULL);
	}
}

int	format_picker(t_fmt fmt, va_list ap)
{
	if (fmt->conversion == 'c')
		return (print_char(fmt, va_arg(ap, int));
	if (fmt->conversion == 's')
		return (print_str(fmt, va_arg(ap, char *));
	if (fmt->conversion == 'p')
		return (print_ptr(fmt, va_arg(ap, void *));
	if (fmt->conversion == 'd' || fmt->conversion == 'i')
		return (print_int(fmt, va_arg(ap, int));
	if (fmt->conversion == 'u' || fmt->conversion == 'x' || fmt->conversion == 'X')
		return (print_unsigned(fmt, va_arg(ap, unsigned int));
	return (0);
}

int	format_str(unsigned char **str, va_list ap)
{
	t_fmt	fmt;
	int		count;

	count = 0;
	if (*(*str + 1) == '%')
	{
		ft_putchar_fd('%', 1);
		*str += 2;
		return (1);
	}
	else
		fmt = parse_format(*str);
	if (!fmt)
	{
		ft_putchar_fd('%', 1);
		*str += 1;
		return (1);
	}
	*str += fmt->len;
	count = format_picker(fmt, ap);
	free(fmt);
	return (count)
}

int	traverse_str(unsigned char *str, va_list ap)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += format_str(&str, ap);
		else
		{
			ft_putchar_fd(*str++, 1);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int				count;
	unsigned char	*str;
	va_list			ap;

	str = (unsigned char *)format;
	va_start(ap, format);
	count = traverse_str(str, ap);
	va_end(ap);
	return (count);
}
