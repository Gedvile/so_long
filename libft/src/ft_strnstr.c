/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:34:22 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/23 16:19:05 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (!little || *little == '\0')
		return ((char *)big);
	while (big && *big != '\0' && len > 0)
	{
		i = 0;
		while (big[i] == little[i] && big[i] != '\0' && little[i] != '\0'
			&& (len - i) > 0)
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return ((char *)0);
}
