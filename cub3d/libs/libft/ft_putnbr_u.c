/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:24:00 by pmagalha          #+#    #+#             */
/*   Updated: 2023/06/05 13:15:08 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr_u(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	ret;

	ret = len_nbr_u(n);
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (ret);
}
