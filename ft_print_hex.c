/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:08:54 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:56 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list args, int uplowcases)
{
	unsigned int	val;
	char			*hex_str;
	int				count;
	char			*base;

	val = va_arg(args, unsigned int);
	if (uplowcases)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	hex_str = ft_itoa_base(val, 16, base);
	if (!hex_str)
		return (-1);
	count = write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}
