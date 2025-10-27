/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:54:21 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/08 11:54:21 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n, char *base)
{
	int				count;
	unsigned int	baselen;

	count = 0;
	baselen = ft_strlen(base);
	if (baselen == 0)
		return (0);
	if (n >= baselen)
		count = ft_putpointer(n / baselen, base);
	count += ft_putchar(base[n % ft_strlen(base)]);
	return (count);
}
