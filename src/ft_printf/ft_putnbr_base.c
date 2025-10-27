/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:20:31 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/12 12:18:37 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base)
{
	int				count;
	unsigned int	baselen;

	count = 0;
	baselen = ft_strlen(base);
	if (n >= baselen)
		count = ft_putnbr_base(n / baselen, base);
	count += ft_putchar(base[n % ft_strlen(base)]);
	return (count);
}

// #include <stdio.h>
// int	main()
// {
// 	int	count;
// 	count = ft_putnbr_base(54442, "0123456789");
// 	// printf("%d \n", count);
// 	return (0);
// }