/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:35:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 15:52:33 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "Hello, world!";
    char *result;

    result = ft_memchr(str, 'o', strlen(str));
    if (result == NULL)
    {
        printf("Character not found\n");
    }
    else
    {
        printf("Character found at position %ld\n", result - str);
    }

    result = ft_memchr(str, 'x', strlen(str));
    if (result == NULL)
    {
        printf("Character not found\n");
    }
    else
    {
        printf("Character found at position %ld\n", result - str);
    }

    return (0);
}
*/
