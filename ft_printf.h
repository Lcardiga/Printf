/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:17:27 by lcardiga          #+#    #+#             */
/*   Updated: 2021/12/13 21:17:38 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_pointer_adress(unsigned long p);
int	ft_pointer_adress2(unsigned long p);
int	ft_decimal(long long n);
int	ft_unsigned_decimal(unsigned long long n);
int	ft_hex(unsigned int n, int type);

#endif
