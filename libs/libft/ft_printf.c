/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:09 by pmagalha          #+#    #+#             */
/*   Updated: 2023/06/05 13:15:18 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	analize(char to_analize, va_list list)
{
	int	ret;

	ret = 0;
	if (to_analize == 's')
		ret += ft_putstr(va_arg(list, char *));
	else if (to_analize == 'c')
		ret += ft_putchar(va_arg(list, int));
	else if (to_analize == 'd' || to_analize == 'i')
		ret += ft_putnbr(va_arg(list, int));
	else if (to_analize == 'u')
		ret += ft_putnbr_u(va_arg(list, unsigned int));
	else if (to_analize == 'x' || to_analize == 'X')
	{
		if (to_analize == 'X')
			ret += ft_print_hexa(va_arg(list, unsigned int), to_analize);
		else
			ret += ft_print_hexa(va_arg(list, unsigned int), to_analize);
	}
	else if (to_analize == 'p')
		ret += ft_print_ptr(va_arg(list, unsigned long));
	else if (to_analize == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	size_t	ret;
	size_t	i;

	va_start(list, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += analize(format[i + 1], list);
			i += 1;
		}
		else
			ret += ft_putchar(format[i]);
		i += 1;
	}
	va_end(list);
	return (ret);
}
/*
int	main(void)
{
	ft_printf("echo");
}*/
