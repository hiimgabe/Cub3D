/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:09 by pmagalha          #+#    #+#             */
/*   Updated: 2023/06/05 13:15:26 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	do_len(size_t n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_hexa(size_t n, const char format)
{
	size_t	len;

	len = do_len(n);
	if (n >= 16)
	{
		ft_print_hexa(n / 16, format);
		ft_print_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + 48);
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
	return (len);
}
/*
int	main(void)
{
	printf("\nlen: %d\n", ft_print_hexa(3302, 'X'));
}
*/
