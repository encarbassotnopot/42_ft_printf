/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:56:45 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 11:30:35 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_format
{
	char			alternate;
	char			padding;
	char			sign;
	unsigned int	min_width;
	unsigned int	precision;
	char			conversion;
}					t_format;

int					ft_printf(const char *format, ...);
#endif
