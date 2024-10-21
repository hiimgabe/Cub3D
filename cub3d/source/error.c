/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:04:55 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/21 19:49:51 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_error(char *file)
{
	ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(file, 2);
    ft_putstr_fd(" is not a valid file.\n", 2);
    return (EXIT_FAILURE);
}

int	file_error(int fd)
{
    (void)fd;
    ft_putstr_fd("Error: File not found\n", 2);
    return (EXIT_FAILURE);
}

void	error_exit(char *error, char *file)
{
	ft_putstr_fd(error, 2);
	exit_free();
	if (file)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
	}
    free_game();
	exit(EXIT_FAILURE);
}