/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:44:44 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/08 17:17:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%.09s\n", NULL);
	printf("%.09s\n", NULL);
	ft_printf("%04d\n", -532);
	printf("%04d\n", -532);
	ft_printf("%0+4d\n", 532);
	printf("%0+4d\n", 532);
	ft_printf("%04d\n", 5032);
	printf("%04d\n", 5032);
}
