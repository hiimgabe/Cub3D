/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/25 11:53:11 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

static void	print_instructions(void)
{
	printf(RED"	           ____  ____\n"RESET);
	printf(RED" ____  _   _  ___ |__  ||  _ \\\n"RESET);
	printf(YELLOW"| ___|| | | || _ \\ __| || | | |\n"RESET);
	printf(GREEN"| |   | | | ||   /|__  || | | |\n"RESET);
	printf(BLUE"| |__ | |_| || _ \\ __| || |_| |\n"RESET);
	printf(PURPLE"|____||_____||___/|____||____/\n"RESET);
	printf(RED"Instructions\n"RESET);
	printf(YELLOW"Forward\t\t: W\t\tBackward\t: S\n"RESET);
	printf(GREEN"Left\t\t: A\t\tRight\t\t: D\n"RESET);
	printf(BLUE"Look left\t: ←\t\tLook right\t: →\n"RESET);
	printf(PURPLE"Show map\t: Spacebar\tShow FPS\t: F\n" RESET);
	printf(RESET"\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_strlen(argv[1]);
		error_exit(ERR_NOMAP, NULL);
	}
	if (file_check(argv[1]))
		exit_free();
	init_game();
	if (parse_data(argv[1]))
		free_game();
	print_instructions();
	start_game();
	free_game();
	return (EXIT_SUCCESS);
}
