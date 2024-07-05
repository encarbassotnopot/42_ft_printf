/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:52 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	char	*str;

	str = "abcd\n";
	printf("conversion: %%5.0ca, val: f\n");
	printf("%d\n", printf("conv og: %5.0ca\nret: ", 'f'));
	printf("%d\n", ft_printf("conv ft: %5.0ca\nret: ", 'f'));
	printf("conversion: %%-5.0ca, val: f\n");
	printf("%d\n", printf("conv og: %-5.0ca\nret: ", 'f'));
	printf("%d\n", ft_printf("conv ft: %-5.0ca\nret: ", 'f'));
	printf("conversion: %%5.0da, val: 0\n");
	printf("%d\n", printf("conv og: %5.0da\nret: ", 0));
	printf("%d\n", ft_printf("conv ft: %5.0da\nret: ", 0));
	printf("conversion: %%5da, val: 15\n");
	printf("%d\n", printf("conv og: %5da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %5da\nret: ", 15));
	printf("conversion: %%-5da, val: 15\n");
	printf("%d\n", printf("conv og: %-5da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %-5da\nret: ", 15));
	printf("conversion: %%+15.7da, val: 15\n");
	printf("%d\n", printf("conv og: %+15.7da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %+15.7da\nret: ", 15));
	printf("conversion: %%+015.7da, val: 15\n");
	printf("%d\n", printf("conv og: %+015.7da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %+015.7da\nret: ", 15));
	printf("conversion: %%5.3da, val: 15\n");
	printf("%d\n", printf("conv og: %+5.3da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %+5.3da\nret: ", 15));
	printf("conversion: %% da, val: -15\n");
	printf("%d\n", printf("conv og: % da\nret: ", -15));
	printf("%d\n", ft_printf("conv ft: % da\nret: ", -15));
	printf("conversion: %%+da, val: 15\n");
	printf("%d\n", printf("conv og: %+da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: %+da\nret: ", 15));
	printf("conversion: %% da, val: 15\n");
	printf("%d\n", printf("conv og: % da\nret: ", 15));
	printf("%d\n", ft_printf("conv ft: % da\nret: ", 15));

	a = 2;
	/*ft_printf("%0-010.12c, %.00s, %p, %d, %i, %u, %x, %X, %0-010.12%\n",
		'c',*/
	/*	"str", &a, a, a, a, a, a);*/
	/*printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 0, 0, 0, 0, 0, 0, 0, 0);*/
	/*// append 0x per a hex, 0 per a octal*/
	/*printf("%#x, %#X, %#o, %%\n", a, a, a);*/
	/*// - si negatiu, + si positiu*/
	/*printf("%+d, %+i, %+d, %+i \n", a, a, -a, -a);*/
	/*// - si negatiu, espai si positiu. la flag ' ' passa per sobre de '+'*/
	/*printf("% d, % i, % d, % i \n", a, a, -a, -a);*/
	/*ft_printf("%#- 0..20d, %o, %020u, %020x, %#002X, %%\n", a, a, a, a, a);*/
	/*// com que no tinc decimals, és equivalent a 0x*/
	/*ft_printf("%.0d, %.0i, %.0u, %.0x, %.0X, %%\n", a, a, a, a, a);*/
	/*printf("%.2d, %.2i, %.2u, %.2x, %.2X, %%\n", a, a, a, a, a);*/
	/*ft_printf("%.5d, %.5i, %.5u, %.5x, %.5X, %%\n", a, a, a, a, a);*/
	/*// 0x: pad with zeros to get minimum len of x*/
	/*ft_printf("%06d, %06i, %06u, %06x, %06X, %%\n", a, a, a, a, a);*/
	/*// pad with spaces*/
	/*ft_printf("%2d, %2i, %2u, %2x, %2X, %%\n", a, a, a, a, a);*/
	/*// - fa pad a la dreta. si s'ha donat flag de '0',
		aquesta queda anulada.*/
	/*ft_printf("%-5d, %-5i, %-5u, %-5x, %-5X, %%\n", a, a, a, a, a);*/
	/*printf("%15c, %15s, %15p, %15d, %15i, %15u, %15x, %15X, %%\n", 'c',
		"str",*/
	/*	&a, a, a, a, a, a);*/
	/*ft_printf("%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#%\n", 0, 0, 0, 0,
		0,*/
	/*	0, 0, 0);*/
}
