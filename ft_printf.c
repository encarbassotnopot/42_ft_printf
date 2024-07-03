/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 12:00:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

// returns -1 if the given char is not one of the following: "#0- +"
// otherwise it returns the index of the function we'll have to call to set it.
int	get_flag_idx(unsigned char c)
{
	if (c == '#')
		return (0);
	if (c == '0')
		return (1);
	if (c == '-')
		return (2);
	if (c == ' ')
		return (3);
	if (c == '+')
		return (4);
	return (-1);
}

t_format	init_format(void)
{
	t_format	fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->alternate = '\0';
	fmt->padding = '\0';
	fmt->sign = '\0';
	fmt->min_width = 0;
	fmt->precision = 0;
	fmt->conversion '\0';
	return (fmt);
}

t_format	parse_format(unsigned char *c)
{
	t_format
		fmt;
	const void	set_flag[]
		(t_format)
		= {set_hash, set_zero, set_minus, set_space, set_plus};

	fmt = init_format();
	if (!fmt)
		return (NULL);
	while (*c && get_flag_idx(*c) != -1)
	{
		set_flag[get_flag_idx(*c)](fmt);
		c++;
	}
}

int	ft_printf(const char *format, ...)
{
	int				count;
	unsigned char	*str;
	va_list			ap;

	count = 0;
	str = (unsigned char *)format;
	va_start(ap, format);
	while (str[count])
	{
		if (str[count] == '%')
		{
			va_arg();
			handle_flags(str + count);
		}
	}
}
