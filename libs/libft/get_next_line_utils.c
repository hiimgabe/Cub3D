/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:43:51 by pmagalha          #+#    #+#             */
/*   Updated: 2024/04/08 17:43:40 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	slen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	str = (char *)malloc(slen(stash) + slen(buffer) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buffer[j])
		str[i++] = buffer[j++];
	str[slen(stash) + slen(buffer)] = '\0';
	free(stash);
	return (str);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*check_emptystring(char *newstr)
{
	if (newstr[0] == '\0')
	{
		free(newstr);
		newstr = 0;
	}
	return (newstr);
}

char	*clean(char *stash)
{
	int		i;
	char	*newstr;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	newstr = (char *)malloc((slen(stash) - i + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
		newstr[j++] = stash[i++];
	newstr[j] = '\0';
	free(stash);
	newstr = check_emptystring(newstr);
	return (newstr);
}
