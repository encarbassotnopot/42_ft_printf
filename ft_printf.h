/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:56:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/05 11:13:11 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include "ft_printf.h"

typedef struct s_fmt
{
	char	alternate;
	char	padding;
	char	sign;
	int		min_width;
	int		precision;
	char	conversion;
	size_t	len;
}			t_fmt;

int			ft_printf(const char *format, ...);
int			ft_printf_fd(const char *format, va_list *ap, int fd);
#endif
