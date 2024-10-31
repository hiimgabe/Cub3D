/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:35:48 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 10:57:27 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buff, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buff;
	while (len > 0)
	{
		*(ptr++) = (unsigned char) c;
		len--;
	}
	return (buff);
}
/*
int	main(void)
{
	char string[] = "aaaaaaaaaa";

	printf("The string before memset is: %s\n", string);
	ft_memset(string + 5, 'z', 5 * sizeof(char));
	printf("The string after memset is: %s\n", string);
}
*/
