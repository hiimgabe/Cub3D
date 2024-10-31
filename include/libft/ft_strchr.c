/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:27:17 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 15:49:16 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}
/*
int	main(void)
{
    char str[] = "Hello, world!";
    char *result;
    char search_char = 'w';
    
    result = ft_strchar(str, search_char);
    
    if (result == NULL)
    {
        printf("'%c' not found in '%s'\n", search_char, str);
    }
    else
    {
        printf("'%c' found at position %ld in '%s'\n", 
	search_char, result - str, str);
    }
    
    return 0;
}*/
