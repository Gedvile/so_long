/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_striteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:13:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/22 15:31:56 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Params:
	s: The string on which to iterate.
	f: The function to apply to each character.
Return:
	None
Ext func:
	None
Descr:
	Applies the function ’f’ on each character of the string passed as
	argument, passing its index as first argument. Each character is
	passed by address to ’f’ to be modified if necessary.
*/
int	ft_is_striteri(char *s, int (*f)(int))
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!f(s[i]))
			return (0);
		i++;
	}
	return (1);
}
