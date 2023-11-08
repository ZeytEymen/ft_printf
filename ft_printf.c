/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:16:45 by ekarabud          #+#    #+#             */
/*   Updated: 2023/11/08 20:54:30 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_putstr(char *s);
int     check_format(char ch)
{
    if (ch == 'c' || ch == 's' || ch == 'p' || 
    ch == 'd' || ch == 'i' || ch == 'u' || 
    ch == 'x' || ch == 'X' || ch == '%')
        return (ch);
    return (0);
}
int ft_putchar(int ch)
{
    return (write(STDOUT_FILENO, &ch, 1));
}
static int	get_size(int n)
{
	int	x;

	x = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		x++;
		n = -n;
	}
	while (n > 0 && x++)
		n /= 10;
        
	return (x);
}
int	ft_putnbr(int number)
{
	if (number == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (number <= 0)
	{
		ft_putchar('-');
		ft_putnbr(-number);
	}
	else if (number > 9)
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	else
		ft_putchar(number + 48);
    return (get_size(number));

}
int ft_putstr(char *s)
{
    int count;

    count = 0;
    while (s[count])
        ft_putchar(s[count++]);
    return (count);
}
int printf_format(char ch, va_list lst)
{
    if (ch == 'c')
        return (ft_putchar(ch));
    else if(ch == 's')
        return (ft_putstr(va_arg(lst, char *)));
    else if(ch == 'i' || ch == 'd')
        return (ft_putnbr(va_arg(lst, int)));
    return (0);
}
int ft_printf(const char *format, ...)
{
    va_list lst;
    int i;
    int count;

    count = 0;
    i = 0;
    va_start(lst,format);
    while (format[i])
    {
        if (format[i] == '%' && check_format(format[i + 1]))
            count += printf_format(format[++i],lst);
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(lst);
    return (0);
}
int main()
{
    char *s1 = "Merhaba";
    char *s2 = "Dunya";
    printf("%u", 15);
    //ft_printf("\n% d\n", -345);
    //ft_printf("%s",s1,s2);
    //ft_printf("%c", 'X');
}