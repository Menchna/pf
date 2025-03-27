/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:18 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:19 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	unsigned long	ptr;
	int				count;
	char			*hex_str;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	hex_str = ft_itoa_base(ptr, 16, "0123456789abcdef");
	if (!hex_str)
		return (-1);
	count += write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}
