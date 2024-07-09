/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:04:55 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/09 14:09:01 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// File for eventual error messages we may need
// Eventually we may condense all of them in one single function

int	map_error(char *file)
{
	ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(file, 2);
    ft_putstr_fd(" is not a valid file.\n", 2);
    return (1);
}

int	file_error(int fd)
{
    (void)fd;
    ft_putstr_fd("Error: File not found\n", 2);
    return (1);
}

void	error_exit(char *error)
{
	ft_putstr_fd(error, 2);
	//clean data
	exit(1);
}