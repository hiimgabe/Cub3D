/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/10/24 16:29:43 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Added this so we can call game()->map for example

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
	printf(YELLOW"Forward\t\t: w\t\tBackward: s\n"RESET);
	printf(GREEN"Left\t\t: a\t\tRight: d\n"RESET);
	printf(BLUE"Look left\t: ←\t\tLook right: →\n"RESET);
	printf(PURPLE"Show map\t:YELLOW Spacebar\n" RESET);
	printf(RESET"\b");
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
