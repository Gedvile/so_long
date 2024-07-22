/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:00:43 by gklimasa          #+#    #+#             */
/*   Updated: 2024/04/03 22:30:53 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototype:
	int	ft_printf(const char *, ...)
Ext funcs:
	malloc, free, write, va_start, va_arg, va_copy, va_end
Descr:
	Write a library that contains ft_printf(), a function that
	will mimic the original printf()

Manndatory part:
	• %c Prints a single character.
	• %s Prints a string (as defined by the common C convention).
	• %p The void * pointer argument has to be printed in hexadecimal format.
	• %d Prints a decimal (base 10) number.
	• %i Prints an integer in base 10.
	• %u Prints an unsigned decimal (base 10) number.
	• %x Prints a number in hexadecimal (base 16) lowercase format.
	• %X Prints a number in hexadecimal (base 16) uppercase format.
	• %% Prints a percent sign.
Bonus part:
	• Manage any combination of the following flags: ’-0.’ and the field
		minimum width under all conversions.
	• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/

#include "libft.h"

static int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_string(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int	parse_format(const char f, va_list args)
{
	if (f == 'c')
		return (print_char(va_arg(args, int)));
	if (f == 's')
		return (print_string(va_arg(args, char *)));
	if (f == 'p')
		return (print_ptr((unsigned long)va_arg(args, void *)));
	if (f == 'd' || f == 'i')
		return (print_nbr(va_arg(args, int)));
	if (f == 'u')
		return (print_nbr(va_arg(args, unsigned int)));
	if (f == 'x' || f == 'X')
		return (print_hex(f, va_arg(args, unsigned int)));
	if (f == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format)
		return (0);
	len = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += parse_format(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
