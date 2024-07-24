/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:13:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:18 by gklimasa         ###   ########.fr       */
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
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		f(i, s + i);
		i++;
	}
}
