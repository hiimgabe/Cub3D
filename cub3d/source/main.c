/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/14 15:44:34 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Added this so we can call game()->map for example

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

static void	print_instructions()
{
	printf(RED"	           ____  ____\n"RESET);
	printf(RED" ____  _   _  ___ |__  ||  _ \\\n"RESET);
	printf(YELLOW"| ___|| | | || _ \\ __| || | | |\n"RESET);
	printf(GREEN"| |   | | | ||   /|__  || | | |\n"RESET);
	printf(BLUE"| |__ | |_| || _ \\ __| || |_| |\n"RESET);
	printf(PURPLE"|____||_____||___/|____||____/\n"RESET);
	printf(RED"Instructions\n"RESET);
	printf(YELLOW"Forward\t\t: w\t\tBackward: s\n"RESET);
	printf(GREEN"Left\t\t: a\t\tRight: d\n"RESET);
	printf(BLUE"Look left\t: ←\t\tLook right: →\n"RESET);
	printf(PURPLE"Show map\t: Spacebar\n" RESET);
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
	if (file_check(argv[1], ".cub", fd))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	init_game();
	if (parse_data(argv[1]))
		free_game();
	print_instructions();
	start_game();
	free_game();
	return (EXIT_SUCCESS);
}
