/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/04 15:45:51 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

void	pad(char **orig, char padding, size_t total_len, char side)
{
	char	*new;
	size_t	orig_len;

	orig_len = ft_strlen(*orig);
	new = malloc(total_len + 1);
	if (!new)
	{
		free(*orig);
		*orig = NULL;
		return ;
	}
	ft_memset(new, padding, total_len);
	if (side == 'l')
		ft_memcpy(new + total_len - orig_len,  *orig, orig_len);
	else if (side == 'r')
		ft_memcpy(new, *orig, orig_len);
	new[total_len + 1] = '\0';
	free(*orig);
	*orig = new;
}

void	pad_spaces(t_fmt *fmt, char **orig)
{
	if (fmt->min_width > (int)ft_strlen(*orig))
	{
		if (fmt->padding == '-')
			pad(orig, ' ', fmt->min_width, 'r');
		else
			pad(orig, ' ', fmt->min_width, 'l');
	}
}

void	pad_zeroes(t_fmt *fmt, char **orig)
{
	if (fmt->precision > (int)ft_strlen(*orig))
	{
		if (fmt->padding == '0')
			pad(orig, '0', fmt->precision, 'l');
	}
}

void	add_sign(t_fmt *fmt, char **orig)
{
	if (fmt->sign)
		pad(orig, fmt->sign, ft_strlen(*orig) + 1, 'l');
}

/*int	print_char(t_fmt *fmt, int arg, int fd);*/
/*int	print_str(t_fmt *fmt, char *arg, int fd);*/
/*int	print_ptr(t_fmt *fmt, void *arg, int fd);*/
int	print_int(t_fmt *fmt, int arg, int fd)
{
	char			*num;
	int				do_print;
	int				len;
	unsigned int	abs;

	num = NULL;
	do_print = 1;
	if (arg < 0)
	{
		fmt->sign = '-';
		abs = ~(arg - 1);
	}
	if (fmt->precision == 0 && arg == 0)
		do_print = 0;
	else
		num = ft_itoa(abs);
	if (do_print)
	{
		pad_zeroes(fmt, &num);
		add_sign(fmt, &num);
	}
	pad_spaces(fmt, &num);
	len = ft_strlen(num);
	ft_putstr_fd(num, fd);
	free(num);
	return (len);
}

/*int	print_unsigned(t_fmt *fmt, unsigned int arg, int fd);*/
