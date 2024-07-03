/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:56:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 16:26:08 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef>;

typedef struct s_fmt
{
	char			alternate;
	char			padding;
	char			sign;
	unsigned int	min_width;
	unsigned int	precision;
	char			conversion;
	size_t			len;
}					t_fmt;

int					ft_printf(const char *format, ...);
#endif
