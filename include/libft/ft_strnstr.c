/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:56:30 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 16:18:30 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	compare;

	if (!little[0])
	{
		return ((char *)(big));
	}
	i = 0;
	while (i < len && big[i])
	{
		compare = 0;
		while (big[i + compare] == little[compare] && i + compare < len)
		{
			if (!little[compare + 1])
			{
				return ((char *)(&big[i]));
			}
			compare++;
		}
		i++;
	}
	return (NULL);
}
