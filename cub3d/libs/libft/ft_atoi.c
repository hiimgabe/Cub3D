/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:41:57 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/17 15:46:10 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = sign * -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * sign);
}
/*
int main()
{
    printf("%d\n", ft_atoi("123")); // Output: 123
    printf("%d\n", ft_atoi("-123")); // Output: -123
    printf("%d\n", ft_atoi("  123")); // Output: 123
    printf("%d\n", ft_atoi("123  ")); // Output: 123
    printf("%d\n", ft_atoi("   123  ")); // Output: 123
    printf("%d\n", ft_atoi("   -123  ")); // Output: -123
    printf("%d\n", ft_atoi("   +123  ")); // Output: 123
    printf("%d\n", ft_atoi("")); // Output: 0
    printf("%d\n", ft_atoi("abc")); // Output: 0
    printf("%d\n", ft_atoi("  123abc")); // Output: 123
    printf("%d\n", ft_atoi("2147483647")); // Output: 2147483647
    printf("%d\n", ft_atoi("-2147483648")); // Output: -2147483648
    printf("%d\n", ft_atoi("2147483648")); // Output: -2147483648
    printf("%d\n", ft_atoi("-2147483649")); // Output: 2147483647
    return 0;
}*/
