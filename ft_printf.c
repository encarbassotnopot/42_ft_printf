/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:27 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/02 17:55:41 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char format *, ...)
{
	int				count;
	unsigned char	*str;
	va_list			ap;

	count = 0;
	str = (unsigned char *)format;
	va_start(ap, format);
	while (str[count])
	{
		if (str[count] = '%')
		{
			va_arg();
			handle_flags(str + count, )
		}
	}
}
