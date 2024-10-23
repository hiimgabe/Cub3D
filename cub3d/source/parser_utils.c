/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:16 by gabe              #+#    #+#             */
/*   Updated: 2024/10/23 10:19:46 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_check(char *file, char *ext, int fd)
{
	size_t	i;
	size_t	ext_len;
	size_t	file_len;
	size_t	dot_count;

	dot_count = 0;
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	i = file_len - ext_len;
	fd = open(file, O_RDONLY);
	while (i > 0)
	{
		if (file[i] == '.')
			dot_count++;
		i--;
	}
	i = file_len - ext_len;
	if (strcmp(file + i, ext) != 0 || (i > 0 && file[i - 1] == '.')
		|| dot_count != 1 || file_len < ext_len)
		return (error_exit(ERR_INVMAPF, file), EXIT_FAILURE);
	if (fd < 0)
		return (error_exit(ERR_FILENTFD, NULL), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
