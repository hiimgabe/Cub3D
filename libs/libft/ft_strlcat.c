/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:25:33 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 15:35:47 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}
/*
#define MAX_LENGTH 50

int	main(void) 
{
    char str1[MAX_LENGTH] = "";
    char str2[0xF] = "nyan !";
    size_t n = MAX_LENGTH - ft_strlen(str1) - 1; 
    // max number of characters that can be appended to str1

    printf("str1 before strlcat(): %s\n", str1);
    printf("str2 before strlcat(): %s\n", str2);

    size_t result = ft_strlcat(((void*)0),str2, 0);

    printf("Result of strlcat(): %zu\n", result);
    printf("str1 after strlcat(): %s\n", str1);
    printf("str2 after strlcat(): %s\n", str2);

    return 0;
}*/
