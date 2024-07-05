/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:01:35 by pmagalha          #+#    #+#             */
/*   Updated: 2024/03/29 14:23:25 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i <= n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	int n;

	n = 5;
	char str1[] = "abcdA";
	char str2[] = "abCdB";

	printf("%d", ft_strncmp(str1, str2, n));
}*/
