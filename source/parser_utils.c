/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:16 by gabe              #+#    #+#             */
/*   Updated: 2024/10/24 15:39:54 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_check(char *file)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (error_exit(ERR_FILENTFD, NULL), EXIT_FAILURE);
	}
	while (i < ft_strlen(file) - 4)
		i++;
	if (ft_strncmp(&file[i], ".cub", 4))
	{
		close(fd);
		return (error_exit(ERR_INVEXT, file), EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}