/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:08:20 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:22 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_length(unsigned long num, int base_len)
{
	int	length;

	length = 1;
	while (num >= (unsigned long)base_len)
	{
		num /= base_len;
		length++;
	}
	return (length);
}

char	*ft_itoa_base(unsigned long num, int base_len, char *base)
{
	char	*str;
	int		length;

	length = get_num_length(num, base_len);
	str = (char *)malloc(length + 1);
	if (!str)
	{
		return (NULL);
	}
	str[length] = '\0';
	while (length--)
	{
		str[length] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
