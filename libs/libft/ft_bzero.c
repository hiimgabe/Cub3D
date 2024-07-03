/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:30:59 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 11:37:48 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = 0;
		n--;
	}
}
/*
int	main(void)
{
	char string[] = "isto eh tudo nada ou zeros";
	printf("%s\n", string);
	ft_bzero(string + 17, 5);
	printf("Depois da ft_bzero, %s\n", string);
	bzero(string + 17, 5);
	printf("Depois da bzero da lib, %s\n", string);
}
*/
