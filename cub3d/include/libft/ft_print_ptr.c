/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:09 by pmagalha          #+#    #+#             */
/*   Updated: 2023/06/05 13:15:20 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + 48);
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	print_lenght;

	print_lenght = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (ptr != 0)
	{
		print_lenght += write(1, "0x", 2);
		ft_put_ptr(ptr);
		print_lenght += ft_ptr_len(ptr);
	}
	return (print_lenght);
}
