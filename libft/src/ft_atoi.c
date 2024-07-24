/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:26:48 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 10:25:44 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(const char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

static int	is_space(const char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

static int	set_sign(int res, int sign)
{
	if (sign == 45)
		return (res * -1);
	else
		return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 0;
	res = 0;
	while (nptr[i] != '\0')
	{
		if (is_sign(nptr[i]) && res == 0)
			sign = sign + nptr[i];
		if (is_sign(nptr[i]) && res != 0)
			break ;
		if (!(sign == 0 || sign == 43 || sign == 45))
			break ;
		if (!is_space(nptr[i]) && !is_sign(nptr[i]) && !ft_isdigit(nptr[i]))
			break ;
		if ((((sign == 43 || sign == 45) && sign != nptr[i]) || res != 0)
			&& !ft_isdigit(nptr[i]))
			break ;
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (set_sign(res, sign));
}
