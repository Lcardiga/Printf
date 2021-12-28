/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:17:19 by lcardiga          #+#    #+#             */
/*   Updated: 2021/12/13 21:17:39 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%c - char
**	%s - string
**	%p - pointer adress
**	%d - decimal
**	%i - decimal
**	%u - unsigned decimal
**	%x - hex lower
**	%X - hex upper
**	%% - print percent
*/

#include "ft_printf.h"

int	ft_checks_symbol(va_list ap, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(ap, int));
	if (format == 's')
		len = ft_putstr(va_arg(ap, char *));
	if (format == 'p')
		len = ft_pointer_adress(va_arg(ap, unsigned long));
	if (format == 'd' || format == 'i')
		len = ft_decimal((long long)va_arg(ap, int));
	if (format == 'u')
		len = ft_unsigned_decimal((unsigned long long)va_arg(ap, unsigned int));
	if (format == 'x')
		len = ft_hex(va_arg(ap, int), 0);
	if (format == 'X')
		len = ft_hex(va_arg(ap, int), 1);
	if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count_length;

	i = 0;
	count_length = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count_length += ft_checks_symbol(ap, format[i + 1]);
			i++;
		}
		else
			count_length += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count_length);
}
