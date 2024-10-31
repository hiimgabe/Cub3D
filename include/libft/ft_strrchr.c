/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:41:56 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 15:49:54 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "azazazazaz";
    char *result = ft_strrchr(str, 'n');

    if (result != NULL)
    {
        printf("The last occurrence of 'l' in '
	%s' is at index %ld.\n", str, result - str);
    }
    else
    {
        printf("No occurrence of 'l' found in '%s'.\n", str);
    }

    return 0;
}*/
