/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:43:17 by pmagalha          #+#    #+#             */
/*   Updated: 2024/03/28 10:00:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	while (*src)
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}
/*
int	main(int argc, char **argv)
{
	char *mine;
	char *library;

	if (argc == 2)
	{
		mine = ft_strdup(argv[1]);
		library = strdup(argv[1]);
		printf(":%s:\n:%s:\n", mine, library);
	}
	return (0);
}*/
