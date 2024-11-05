/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:30 by gabe              #+#    #+#             */
/*   Updated: 2024/11/05 14:38:07 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_valid_xpm_file(char *xpm)
{
	int		len;
	char	*extention;

	if (xpm[0] != '.')
		return (EXIT_FAILURE);
	len = ft_strlen(xpm);
	extention = ft_substr(xpm, len - 4, 4);
	if (!strncmp(extention, ".xpm", 4))
	{
		free(extention);
		return (EXIT_SUCCESS);
	}
	free(extention);
	return (EXIT_FAILURE);
}

int	check_xpm(void)
{
	if (!game()->map->no || !game()->map->so
		|| !game()->map->we || !game()->map->ea)
		return (EXIT_FAILURE);
	if (is_valid_xpm_file(game()->map->so)
		|| is_valid_xpm_file(game()->map->no)
		|| is_valid_xpm_file(game()->map->we)
		|| is_valid_xpm_file(game()->map->ea))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
