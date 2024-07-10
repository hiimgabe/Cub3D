/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:01:43 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 15:34:06 by gabe             ###   ########.fr       */
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
	if (argc != 2)
		return (ft_putstr_fd("Error: wrong number of arguments.\n", 2), 1);

	init_game();
	if (parse_data(argv[1]))
		return (error_exit("Parsing error.\n"), EXIT_FAILURE);
	start_game();
	return (EXIT_SUCCESS);
}