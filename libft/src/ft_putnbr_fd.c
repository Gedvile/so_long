/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:28:13 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 00:43:36 by gklimasa         ###   ########.fr       */
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

/*
Params:
	n: The integer to output.
	fd: The file descriptor on which to write.
Return:
	None
Ext func:
	write
Descr:
	Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int		digits;
	int		sign;
	char	res;

	sign = 1;
	digits = get_digits(n);
	digits = ft_pow(10, digits - 1);
	if (n < 0)
	{
		sign = -1;
		write(fd, &"-", 1);
	}
	while (digits != 0)
	{
		res = (sign * (n / digits)) + '0';
		n = n % digits;
		digits = digits / 10;
		write(fd, &res, 1);
	}
}
