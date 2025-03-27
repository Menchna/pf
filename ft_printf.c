/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:46 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:47 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_argument(int c)
{
	return (c == 'c' || c == 's' || c == '%' || c == 'd' || c == 'i' \
			|| c == 'p' || c == 'x' || c == 'X' || c == 'u');
}

int	ft_formats(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_char(args));
	else if (specifier == 's')
		return (ft_print_string(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_decimal(args));
	else if (specifier == 'p')
		return (ft_print_pointer(args));
	else if (specifier == 'u')
		return (ft_print_unsigned_decimal(args));
	else if (specifier == 'x')
		return (ft_print_hex(args, 0));
	else if (specifier == 'X')
		return (ft_print_hex(args, 1));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *prm, ...)
{
	va_list	args;
	int		len;
	int		res;

	len = 0;
	va_start(args, prm);
	while (*prm)
	{
		if (*prm == '%')
		{
			prm++;
			if (ft_is_argument(*prm))
				res = ft_formats(args, *prm);
		}
		else
			res = ft_putchar(*prm);
		prm++;
		if (res == -1)
			return (-1);
		len += res;
	}
	va_end(args);
	return (len);
}
/*
int main(void)
{
    int num = 42;
    unsigned int u_num = 123456;
    void *ptr = &num;
	void *null_ptr = NULL;

	ft_printf("Hello, %s\n", "world!");  // String
	ft_printf("Character: %c\n", 'A');  // Character
	ft_printf("Integer: %d\n", num);  // Decimal
	ft_printf("Integer (%%i): %i\n", -99);  // Integer with %i
	ft_printf("Unsigned: %u\n", u_num);  // Unsigned integer
	ft_printf("Pointer: %p\n", ptr);  // Pointer
	ft_printf("NULL Pointer: %p\n", null_ptr);   // NULL pointer case
	ft_printf("Hex (lowercase): %x\n", num);  // Hexadecimal lowercase
	ft_printf("Hex (uppercase): %X\n", num);  // Hexadecimal uppercase
	ft_printf("Percent sign: %%\n");  // Percent sign
	printf("\n");
	printf("Hello, %s\n", "world!");
	printf("Character: %c\n", 'A');
 	printf("Integer: %d\n", num);
	printf("Integer (%%i): %i\n", -99);
 	printf("Unsigned: %u\n", u_num);
 	printf("Pointer: %p\n", ptr);
 	printf("NULL Pointer: %p\n", null_ptr);
  	printf("Hex (lowercase): %x\n", num);
   	printf("Hex (uppercase): %X\n", num);
    	printf("Percent sign: %%\n");
}
*/
