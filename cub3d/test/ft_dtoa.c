/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:10:01 by gabe              #+#    #+#             */
/*   Updated: 2024/10/17 22:20:35 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int	int_cnt(int intpart)
{
	int	size;

	size = 0;
	while (1)
	{
		intpart = intpart / 10;
		size++;
		if (intpart == 0)
			break ;
	}
	return (size);
}

int	*dtoa_size(double n, int decimal_n)
{
	int		*size;
	int		intpart;
	double	dbpart;

	size = malloc(sizeof(int) * 2);
	size[0] = 0;
	size[1] = 0;
	if (n < 0)
	{
		n *= -1;
		size[0]++;
	}
	intpart = (int)n;
	size[0] += int_cnt(intpart);
	while (size[1] < decimal_n)
	{
		dbpart = dbpart - intpart;
		dbpart = dbpart * 10;
		intpart = (int)dbpart;
		size[1]++;
	}
	return (size);
}

void	decimal_placer(char *res, double dbpart, int decimal_n, int t_size)
{
	int	inthelper;
	int	power;

	power = pow(10, decimal_n);
	dbpart *= power;
	inthelper = (int)dbpart;
	while (decimal_n > 0)
	{
		res[t_size] = (inthelper % 10) + '0';
		t_size--;
		inthelper /= 10;
		decimal_n--;
	}
}

char	*ft_dtoa(double n, int decimal_n)
{
	char	*res;
	int		*size;
	int		intpart;
	double	dbpart;

	size = dtoa_size(n, decimal_n);
	res = malloc(sizeof(char) * (size[0] + size[1] + 3));
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	intpart = (int)n;
	dbpart = n - intpart;
	res[size[0]] = '.';
	decimal_placer(res, dbpart, decimal_n, size[0] + size[1]);
	while (--size[0] >= 0)
	{
		res[size[0]] = (intpart % 10) + '0';
		intpart /= 10;
		if (res[0] == '-' && size[0] == 1)
			break ;
	}
	free(size);
	return (res);
}

int main()
{
	double	n = 123.123;
	int		intpart;
	char *test;

	int	casasdecimais;

	test = ft_dtoa(123.123, 3);

	casasdecimais = 1 * 1000;

	intpart = (int)n;
	n = n - intpart;
	intpart = (int)(n * 1000);
	printf("%d\n", test[7]);
	return (0);
}
