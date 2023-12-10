/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:16:45 by ekarabud          #+#    #+#             */
/*   Updated: 2023/12/10 20:35:24 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(int ch)
{
	return (write(STDOUT_FILENO, &ch, 1));
}

int	check_format(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p'
		|| ch == 'd' || ch == 'i' || ch == 'u'
		|| ch == 'x' || ch == 'X' || ch == '%')
		return (1);
	return (0);
}

int	printf_format(char ch, va_list lst)
{
	if (ch == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (ch == '%')
		return (ft_putchar('%'));
	else if (ch == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (ch == 'i' || ch == 'd')
		return (ft_putnbr(va_arg(lst, int), 0));
	else if (ch == 'p')
		return (ft_print_ptr(va_arg(lst, unsigned long), 42, 0));
	else if (ch == 'x' || ch == 'X')
		return (ft_print_hex(va_arg(lst, unsigned int), ch, 0));
	else if (ch == 'u')
		return (ft_print_unsigned(va_arg(lst, unsigned int), 0));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(lst, format);
	while (format[i])
	{
		if (format[i] == '%' && check_format(format[i + 1]))
			count += printf_format(format[++i], lst);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(lst);
	return (count);
}
