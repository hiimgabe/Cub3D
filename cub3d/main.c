/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/30 11:34:57 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Added this so we can call game()->map for example

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error: no map file provided.\n", 2);
		return (1);
	}
	
	// This is where we check the file extension
	if (file_check(argv[1], ".cub", fd))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	
	// This is where we init		
	init_game();

	// This where we parse 
	if (!parse_data(argv[1]))
		free_game();
		
	printf("Exiting successfull\n");
	free_game();
	return (EXIT_SUCCESS);
}