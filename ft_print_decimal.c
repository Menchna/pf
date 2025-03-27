/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:08:45 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:46 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list args)
{
	int		val;
	char	*str;
	int		len;

	val = va_arg(args, int);
	str = ft_itoa(val);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
