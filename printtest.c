/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:52 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/07/08 12:34:57 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	char	*str;

	printf("%d\n", printf("og c: %05.2c, s:%-05.1sa\nret: ", 'c',
			"1234567890"));
	printf("%d\n", ft_printf("ft c: %05.2c, s:%-05.1sa\nret: ", 'c',
			"1234567890"));
	printf("%d\n", printf("og c: %05.2c, s:%.7sa\nret: ", 'c', "1234567890"));
	printf("%d\n", ft_printf("ft c: %05.2c, s:%.7sa\nret: ", 'c',
			"1234567890"));
	printf("%d\n", printf("og c: %05.2c, s:%.12sa\nret: ", 'c', "1234567890"));
	printf("%d\n", ft_printf("ft c: %05.2c, s:%.12sa\nret: ", 'c',
			"1234567890"));
	printf("%d\n", printf("og c: %05.2c, s:%+-10.9sa\nret: ", 'c',
			"1234567890"));
	printf("%d\n", ft_printf("ft c: %05.2c, s:%+-10.9sa\nret: ", 'c',
			"1234567890"));
	printf("conversion: %%5.0ca, val: f\n");
	printf("%d\n", printf("conv og: %5.0ca\nret: ", 'f'));
	printf("%d\n", ft_printf("conv ft: %5.0ca\nret: ", 'f'));
	printf("conversion: %%-5.0ca, val: f\n");
	printf("%d\n", printf("conv og: %-5.0ca\nret: ", 'f'));
	printf("%d\n", ft_printf("conv ft: %-5.0ca\nret: ", 'f'));
	printf("conversion: %%5.0xa, val: 0\n");
	printf("%d\n", printf("conv og: %5.0xa\nret: ", 0));
	printf("%d\n", ft_printf("conv ft: %5.0xa\nret: ", 0));
	printf("conversion: %%5xa, val: 123\n");
	printf("%d\n", printf("conv og: %5xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %5xa\nret: ", 123));
	printf("conversion: %%-5xa, val: 123\n");
	printf("%d\n", printf("conv og: %-5xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %-5xa\nret: ", 123));
	printf("conversion: %%+15.7xa, val: 123\n");
	printf("%d\n", printf("conv og: %+15.7xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+15.7xa\nret: ", 123));
	printf("conversion: %%+015.7xa, val: 123\n");
	printf("%d\n", printf("conv og: %+015.7xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+015.7xa\nret: ", 123));
	printf("conversion: %%5.3xa, val: 123\n");
	printf("%d\n", printf("conv og: %+5.3xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+5.3xa\nret: ", 123));
	printf("conversion: %% xa, val: -123\n");
	printf("%d\n", printf("conv og: % xa\nret: ", -123));
	printf("%d\n", ft_printf("conv ft: % xa\nret: ", -123));
	printf("conversion: %%+xa, val: 123\n");
	printf("%d\n", printf("conv og: %+xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+xa\nret: ", 123));
	printf("conversion: %% xa, val: 123\n");
	printf("%d\n", printf("conv og: % xa\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: % xa\nret: ", 123));
	printf("conversion: %%5.0da, val: 0\n");
	printf("%d\n", printf("conv og: %5.0da\nret: ", 0));
	printf("%d\n", ft_printf("conv ft: %5.0da\nret: ", 0));
	printf("conversion: %%5da, val: 123\n");
	printf("%d\n", printf("conv og: %5da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %5da\nret: ", 123));
	printf("conversion: %%-5da, val: 123\n");
	printf("%d\n", printf("conv og: %-5da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %-5da\nret: ", 123));
	printf("conversion: %%+15.7da, val: 123\n");
	printf("%d\n", printf("conv og: %+15.7da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+15.7da\nret: ", 123));
	printf("conversion: %%+015.7da, val: 123\n");
	printf("%d\n", printf("conv og: %+015.7da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+015.7da\nret: ", 123));
	printf("conversion: %%5.3da, val: 123\n");
	printf("%d\n", printf("conv og: %+5.3da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+5.3da\nret: ", 123));
	printf("conversion: %% da, val: -123\n");
	printf("%d\n", printf("conv og: % da\nret: ", -123));
	printf("%d\n", ft_printf("conv ft: % da\nret: ", -123));
	printf("conversion: %%+da, val: 123\n");
	printf("%d\n", printf("conv og: %+da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: %+da\nret: ", 123));
	printf("conversion: %% da, val: 123\n");
	printf("%d\n", printf("conv og: % da\nret: ", 123));
	printf("%d\n", ft_printf("conv ft: % da\nret: ", 123));
	a = 2435;
	printf("%0-010.12c, %.00s, %p, %d, %i, %u, %x, %X, %0-010.12%\n", 'c', "str", &a, a, a, a, a, a);
	ft_printf("%0-010.12c, %.00s, %p, %d, %i, %u, %x, %X, %0-010.12%\n", 'c', "str", &a, a, a, a, a, a);
	printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 0, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 0, 0, 0, 0, 0, 0, 0, 0);
	printf("%#x, %#X, %#o, %%\n", a, a, a);
	ft_printf("%#x, %#X, %#o, %%\n", a, a, a);
	printf("%+d, %+i, %+d, %+i \n", a, a, -a, -a);
	ft_printf("%+d, %+i, %+d, %+i \n", a, a, -a, -a);
	printf("% d, % i, % d, % i \n", a, a, -a, -a);
	ft_printf("% d, % i, % d, % i \n", a, a, -a, -a);
	printf("%012.5d, %012.5o, %012.5u, %012.5x, %#012.5X, %%\n", a, a, a, a, a);
	ft_printf("%012.5d, %012.5o, %012.5u, %012.5x, %#012.5X, %%\n", a, a, a, a, a);
	printf("%- 030.20d, %- 030.20o, %- 030.20u, %- 030.20x, %#002X, %%\n", a, a, a, a, a);
	ft_printf("%- 030.20d, %- 030.20o, %- 030.20u, %- 030.20x, %#002X, %%\n", a, a, a, a, a);
	printf("%.0d, %.0i, %.0u, %.0x, %.0X, %%\n", a, a, a, a, a);
	ft_printf("%.0d, %.0i, %.0u, %.0x, %.0X, %%\n", a, a, a, a, a);
	printf("%.2d, %.2i, %.2u, %.2x, %.2X, %%\n", a, a, a, a, a);
	ft_printf("%.2d, %.2i, %.2u, %.2x, %.2X, %%\n", a, a, a, a, a);
	printf("%.5d, %.5i, %.5u, %.5x, %.5X, %%\n", a, a, a, a, a);
	ft_printf("%.5d, %.5i, %.5u, %.5x, %.5X, %%\n", a, a, a, a, a);
	printf("%6d, %6i, %6u, %6x, %6X, %%\n", a, a, a, a, a);
	ft_printf("%6d, %6i, %6u, %6x, %6X, %%\n", a, a, a, a, a);
	printf("%06d, %06i, %06u, %06x, %06X, %%\n", a, a, a, a, a);
	ft_printf("%06d, %06i, %06u, %06x, %06X, %%\n", a, a, a, a, a);
	printf("%2d, %2i, %2u, %2x, %2X, %%\n", a, a, a, a, a);
	ft_printf("%2d, %2i, %2u, %2x, %2X, %%\n", a, a, a, a, a);
	printf("%-5d, %-5i, %-5u, %-5x, %-5X, %%\n", a, a, a, a, a);
	ft_printf("%-5d, %-5i, %-5u, %-5x, %-5X, %%\n", a, a, a, a, a);
	printf("%15c, %15s, %15p, %15d, %15i, %15u, %15x, %15X, %%\n", 'c', "str", &a, a, a, a, a, a);
	ft_printf("%15c, %15s, %15p, %15d, %15i, %15u, %15x, %15X, %%\n", 'c', "str", &a, a, a, a, a, a);
	printf("%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#34%\n", 0, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#34%\n", 0, 0, 0, 0, 0, 0, 0, 0);
}
