/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:20:06 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/18 08:44:06 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*set_malloc(int n, int digits)
{
	char	*res;

	if (n < 0)
		res = malloc((digits + 2) * sizeof(char));
	else
		res = malloc((digits + 1) * sizeof(char));
	return (res);
}

static int	ft_pow(int base, int power)
{
	int	x;

	x = base;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		x *= base;
		power--;
	}
	return (x);
}

static char	*set_end_of_string(char *res, int i)
{
	res[i] = '\0';
	return (res);
}

/*
Params:
	n: the integer to convert.
	The string representing the integer.
Return:
	NULL if the allocation fails.
Ext func:
	malloc
Descr:
	Allocates (with malloc(3)) and returns a string representing
	the integer received as an argument. Negative numbers must be handled.
 */
char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		digits;
	int		i;

	digits = get_digits(n);
	res = set_malloc(n, digits);
	if (res == NULL)
		return (NULL);
	i = 0;
	sign = 1;
	digits = ft_pow(10, digits - 1);
	if (n < 0)
	{
		res[i++] = '-';
		sign = -1;
	}
	while (digits != 0)
	{
		res[i++] = (sign * (n / digits)) + '0';
		n = n % digits;
		digits = digits / 10;
	}
	return (set_end_of_string(res, i));
}
