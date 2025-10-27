/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:52:22 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/15 20:49:46 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf2(const char s, va_list ap)
{
	unsigned long	ptr;

	if (s == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (s == 'p')
	{
		ptr = (unsigned long int)va_arg(ap, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_putpointer(ptr, "0123456789abcdef"));
	}
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (s == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
	else if (s == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (s == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (s == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	lst;

	count = 0;
	va_start(lst, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += ft_printf2(*s, lst);
		}
		else
			count += ft_putchar(s[0]);
		s++;
	}
	va_end(lst);
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
//     int ret1 = printf("printf officiel : [ %p %p ]\n", (void *)0, (void *)0);
//     int ret2 = ft_printf("ft_printf perso : [ %p %p ]\n", 0, 0);

//     printf("Return printf    : %d\n", ret1);
//     printf("Return ft_printf : %d\n", ret2);

//     return 0;
// }