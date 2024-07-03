/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:23:12 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/03 11:27:48 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hash(t_format fmt)
{
	if (!fmt)
		return ;
	fmt->alternate = '#';
}

void	set_zero(t_format fmt)
{
	if (!fmt)
		return ;
	if (fmt->padding == '-')
		return ;
	fmt->padding = '0';
}

void	set_minus(t_format fmt)
{
	if (!fmt)
		return ;
	fmt->padding = '-';
}

void	set_space(t_format fmt)
{
	if (!fmt)
		return ;
	if (fmt->signpadding == '+')
		return ;
	fmt->sign = ' ';
}

void	set_plus(t_format fmt)
{
	if (!fmt)
		return ;
	fmt->sign = '+';
}
