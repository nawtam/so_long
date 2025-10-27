/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:49:11 by ntamacha          #+#    #+#             */
/*   Updated: 2025/10/20 12:35:56 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int				ft_printf(const char *s, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
int				ft_putnbr_base(unsigned int n, char *base);
int				ft_putpointer(unsigned long n, char *base);
int				ft_strlen(char *str);

#endif