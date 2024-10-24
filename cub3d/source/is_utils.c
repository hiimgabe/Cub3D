/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:28:34 by gabe              #+#    #+#             */
/*   Updated: 2024/10/24 16:24:39 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_floor(char c)
{
	return (c == '0');
}

bool	is_wall(char c)
{
	return (c == '1');
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

bool	isdigitarray(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		printf("%c\n", str[i]);
		if (!ft_isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}
