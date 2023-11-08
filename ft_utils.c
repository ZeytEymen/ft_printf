/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:23:11 by ekarabud          #+#    #+#             */
/*   Updated: 2023/11/08 19:23:45 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int ch)
{
    return (write(STDOUT_FILENO, &ch, 1));
}

int ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
        ft_putchar(s[i++]);
    return (i);
}