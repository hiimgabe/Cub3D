/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:13:53 by gabe              #+#    #+#             */
/*   Updated: 2024/11/05 17:30:52 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_textures(char **textures)
{
	textures[0] = "SO";
	textures[1] = "NO";
	textures[2] = "WE";
	textures[3] = "EA";
	textures[4] = "F";
	textures[5] = "C";
	textures[6] = NULL;
}

static char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
	}
	return (0);
}

static char	*trim_map_texture(char *line, char **textures)
{
	int		i;
	char	*new;
	char	*strstr;

	i = -1;
	while (textures[++i])
	{
		strstr = ft_strstr(line, textures[i]);
		if (strstr)
		{
			new = ft_substr(strstr, 0, ft_strlen(strstr));
			if (!new)
				return (NULL);
			return (new);
		}
	}
	return (ft_strdup(line));
}

static void	clean_assign(char *str, char **texture)
{
	int	i;
	int	j;

	if (!str && !*str)
		return ;
	i = 0;
	while (is_space(str[i]))
		i++;
	j = ft_strlen(str) - 1;
	while (is_space(str[j]))
		j--;
	if (str[j] == '\n')
		j--;
	*texture = ft_substr(str, i, j - i + 1);
}

bool	dup_text(char *trim)
{
	if (!ft_strncmp(trim, "NO", 2) && game()->map->no != 0)
		return (true);
	if (!ft_strncmp(trim, "SO", 2) && game()->map->so != 0)
		return (true);
	if (!ft_strncmp(trim, "EA", 2) && game()->map->ea != 0)
		return (true);
	if (!ft_strncmp(trim, "WE", 2) && game()->map->we != 0)
		return (true);
	if (!ft_strncmp(trim, "F", 1) && game()->map->f != 0)
		return (true);
	if (!ft_strncmp(trim, "C", 1) && game()->map->c != 0)
		return (true);
	return (false);
}

int	parse_map_textures(char *line)
{
	char	*textures[7];
	char	*trim;

	init_textures(textures);
	trim = trim_map_texture(line, textures);
	if (dup_text(trim))
		return (free(trim), EXIT_FAILURE);
	if (trim[0] == 'S' && trim[1] == 'O')
		clean_assign(&trim[2], &game()->map->so);
	else if (trim[0] == 'N' && trim[1] == 'O')
		clean_assign(&trim[2], &game()->map->no);
	else if (trim[0] == 'W' && trim[1] == 'E')
		clean_assign(&trim[2], &game()->map->we);
	else if (trim[0] == 'E' && trim[1] == 'A')
		clean_assign(&trim[2], &game()->map->ea);
	else if (trim[0] == 'F' && trim[1] == ' ')
		clean_assign(&trim[2], &game()->map->f);
	else if (trim[0] == 'C' && trim[1] == ' ')
		clean_assign(&trim[2], &game()->map->c);
	free(trim);
	return (EXIT_SUCCESS);
}
