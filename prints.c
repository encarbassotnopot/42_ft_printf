/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/06 10:27:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

void	pad(char **orig, char pad_ch, size_t total_len, char side)
{
	char	*new;
	char	*pad;
	size_t	orig_len;
	size_t	pad_len;

	orig_len = ft_strlen(*orig);
	pad_len = total_len - orig_len;
	pad = ft_calloc(pad_len + 1, sizeof(char));
	if (!pad)
	{
		free(*orig);
		*orig = NULL;
		return ;
	}
	ft_memset(pad, pad_ch, pad_len);
	if (side == 'l')
		new = ft_strjoin(pad, *orig);
	else if (side == 'r')
		new = ft_strjoin(*orig, pad);
	free(*orig);
	free(pad);
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
	if (fmt->precision < 0)
		return ;
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

	out = ft_substr(arg, 0, fmt->precision);
	if (!out)
		return (0);
	pad_spaces(fmt, &out);
	len = ft_strlen(out);
	ft_putstr_fd(out, fd);
	free(out);
	return (len);
}

/*int	print_ptr(t_fmt *fmt, void *arg, int fd)*/
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

char *get_nbr_base (unsigned int num, char base)
{
	if (base == 'o')
		return (ft_utoa_base(num, "01234567"))
	if (base == 'u')
		return (ft_utoa_base(num, "0123456789"))
	if (base == 'x')
		return (ft_utoa_base(num, "0123456789abcdef"))
	if (base == 'X')
		return (ft_utoa_base(num, "0123456789ABCDEF"))
	return (NULL);
}

int	print_unsigned(t_fmt *fmt, unsigned int arg, int fd)
{
	char	*num;
	int		len;

	if (!(fmt->precision == 0 && arg == 0))
	{
		num = ft_utoa_base((unsigned int)arg);
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
