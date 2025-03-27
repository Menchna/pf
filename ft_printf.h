/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:11:02 by armkhach          #+#    #+#             */
/*   Updated: 2025/03/12 20:11:02 by armkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *prm, ...);
int		ft_is_argument(int c);
int		ft_formats(va_list args, char specifier);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_decimal(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_unsigned_decimal(va_list args);
int		ft_print_hex(va_list args, int uppercase);
int		ft_print_percent(void);
int		ft_putchar(char c);
char	*ft_itoa_base(unsigned long num, int base_len, char *base);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);

#endif  // end of FT_PRINTF_H
