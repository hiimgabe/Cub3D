/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:42:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/06/05 13:15:06 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = len_nbr(n);
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (ret);
}
/*
int	main(void)
{
	printf("nlen: %d\n", ft_putnbr(2147483648));
}*/
