/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:00:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/29 16:51:19 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert_recursive(unsigned long n, char *base, int blen, int *plen)
{
	if (n != 0)
	{
		convert_recursive(n / blen, base, blen, plen);
		ft_putchar_fd(base[n % blen], 1);
		(*plen)++;
	}
	else
		return ;
}

int	print_nbr(long arg)
{
	int	len;
	int	*ptrlen;

	if (arg == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 0;
	if (arg < 0)
	{
		len++;
		ft_putchar_fd('-', 1);
		arg *= -1;
	}
	ptrlen = &len;
	convert_recursive(arg, "0123456789", 10, ptrlen);
	return (len);
}

int	print_ptr(unsigned long arg)
{
	int	len;
	int	*ptrlen;

	if (arg == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", 1);
	len = ft_strlen("0x");
	ptrlen = &len;
	convert_recursive(arg, "0123456789abcdef", 16, ptrlen);
	return (len);
}

int	print_hex(const char f, unsigned int arg)
{
	char	*hexbase;
	int		len;
	int		*ptrlen;

	if (arg == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 0;
	ptrlen = &len;
	if (f == 'X')
		hexbase = "0123456789ABCDEF";
	else
		hexbase = "0123456789abcdef";
	convert_recursive(arg, hexbase, ft_strlen(hexbase), ptrlen);
	return (len);
}
