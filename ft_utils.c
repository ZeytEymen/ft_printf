/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:23:11 by ekarabud          #+#    #+#             */
/*   Updated: 2023/12/10 20:06:19 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	while (s[count])
		ft_putchar(s[count++]);
	return (count);
}

int	ft_putnbr(int number, int count)
{
	if (number == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (number < 0)
	{
		count += ft_putchar('-');
		count = ft_putnbr(-number, count);
	}
	else if (number >= 10)
	{
		count = ft_putnbr(number / 10, count);
		count = ft_putnbr(number % 10, count);
	}
	else
		count += ft_putchar(number + '0');
	return (count);
}

int	ft_print_ptr(unsigned long n, int firstCall, int number)
{
	if (firstCall == 42)
	{
		number += ft_putstr("0x");
		number = ft_print_ptr(n, 0, number);
	}
	else
	{
		if (n >= 16)
			number = ft_print_ptr(n / 16, 0, number);
		number += ft_putchar("0123456789abcdef"[n % 16]);
	}
	return (number);
}

int	ft_print_hex(unsigned long n, char ch, int number)
{
	if (n >= 16)
		number = ft_print_hex(n / 16, ch, number);
	if (ch == 'x')
		number += ft_putchar("0123456789abcdef"[n % 16]);
	else
		number += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (number);
}

int	ft_print_unsigned(unsigned int n, int number)
{
	if (n >= 10)
	{
		number = ft_print_unsigned(n / 10, number);
		number = ft_print_unsigned(n % 10, number);
	}
	else
		number += ft_putchar(n + '0');
	return (number);
}
