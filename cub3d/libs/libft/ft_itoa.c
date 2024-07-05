/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:15:26 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/28 11:14:53 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = f_size(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
int main()
{
    printf("Input: %d\nResult: %s\n\n", 0, ft_itoa(0));
    printf("Input: %d\nResult: %s\n\n", 9, ft_itoa(9));
    printf("Input: %d\nResult: %s\n\n", -9, ft_itoa(-9));
    printf("Input: %d\nResult: %s\n\n", 10, ft_itoa(10));
    printf("Input: %d\nResult: %s\n\n", 8124, ft_itoa(8124));
    printf("Input: %d\nResult: %s\n\n", -9874, ft_itoa(-9874));
    printf("Input: %d\nResult: %s\n\n", 543000, ft_itoa(543000));
    printf("Input: %lld\nResult: %s\n\n", -2147483648LL, ft_itoa(-2147483648LL));
    printf("Input: %d\nResult: %s\n\n", 2147483647, ft_itoa(2147483647));
}*/
