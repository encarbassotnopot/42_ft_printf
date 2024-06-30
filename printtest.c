/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:52 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/30 21:18:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	a;

	a = -3842;
	printf("%d\n");
	printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'c', "str", &a, a, a, a, a, a);
	printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 0, 0, 0, 0, 0, 0, 0, 0);
 //append 0x per a hex, 0 per a octal
	printf("%#x, %#X, %#o, %%\n", a, a, a);
	// - si negatiu, + si positiu
	printf("%+d, %+i, %+d, %+i \n", a, a, -a, -a);
	// - si negatiu, espai si positiu. la flag ' ' passa per sobre de '+'
	printf("% d, % i, % d, % i \n", a, a, -a, -a);
	printf("%0d, %0i, %0u, %0x, %0X, %%\n", a, a, a, a, a);
	// com que no tinc decimals, és equivalent a 0x
	printf("%.0d, %.0i, %.0u, %.0x, %.0X, %%\n", a, a, a, a, a);
	printf("%.2d, %.2i, %.2u, %.2x, %.2X, %%\n", a, a, a, a, a);
	printf("%.5d, %.5i, %.5u, %.5x, %.5X, %%\n", a, a, a, a, a);
	// 0x: pad with zeros to get minimum len of x
	printf("%06d, %06i, %06u, %06x, %06X, %%\n", a, a, a, a, a); 
	// pad with spaces
	printf("%2d, %2i, %2u, %2x, %2X, %%\n", a, a, a, a, a);
	// - fa pad a la dreta. si s'ha donat flag de '0', aquesta queda anulada.
	printf("%-5d, %-5i, %-5u, %-5x, %-5X, %%\n", a, a, a, a, a);
	printf("%15c, %15s, %15p, %15d, %15i, %15u, %15x, %15X, %%\n", 'c', "str", &a, a, a, a, a, a);
	/*printf("%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#%\n", 0, 0, 0, 0, 0, 0, 0, 0);*/
}
