/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:27:31 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:27:52 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	show_fps(long int old_time)
{
	long int	curr_time;
	double		fps;
	char		*fps_a;

	curr_time = get_time();
	fps = (curr_time - old_time) / 1000.0;
	fps = 1.0 / fps;
	fps_a = ft_dtoa(fps, 3);
	mlx_string_put(game()->mlx, game()->mlx_win, 5, 795, 0xFFFFFF, fps_a);
	free(fps_a);
}

long	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}
