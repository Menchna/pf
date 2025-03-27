/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:09:35 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:36 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list args)
{
	unsigned int	val;
	int				len;
	char			*str;

	val = va_arg(args, unsigned int);
	str = ft_itoa_base(val, 10, "0123456789");
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
