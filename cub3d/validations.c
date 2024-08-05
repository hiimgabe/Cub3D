/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:10:49 by gabe              #+#    #+#             */
/*   Updated: 2024/08/01 10:21:21 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	extension_valid(char *extension)
{
	if (ft_strlen(extension) > 3)
		return (EXIT_FAILURE);
	if (ft_strncmp(extension, "xpm", 3))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_extension(char *str)
{
	char	*extension;
	int		i;

	i = 0;
	extension = NULL;
	while (str[i] != '.')
		i++;
	while (*str)
	{
		extension[i] = *str;
		str++;
		i++; 
	}
	if (extension_valid(extension))
		return (error_exit("Invalid file extension.\n"),EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*int	floor_ceiling_valid(char *str)
{
	
}*/