/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:51:48 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	copy_texture2(t_game *game, char *c, char *str)
{
	if (!ft_strncmp(c, "NO", 2))
	{
		if (game->tex.nord == 0)
			game->tex.nord = ft_strtrim(str, " ");
		else
			return (1);
	}
	if (!ft_strncmp(c, "WE", 2))
	{
		if (game->tex.ovest == 0)
			game->tex.ovest = ft_strtrim(str, " ");
		else
			return (1);
	}
	return (0);
}

int	copy_texture(t_game *game, char *c, char *str)
{
	if (!ft_strncmp(c, "SO", 2))
	{
		if (game->tex.sud == 0)
			game->tex.sud = ft_strtrim(str, " ");
		else
			return (1);
	}
	if (!ft_strncmp(c, "EA", 2))
	{
		if (game->tex.est == 0)
			game->tex.est = ft_strtrim(str, " ");
		else
			return (1);
	}
	return (0);
}

//divide la linea in matrice
int	take_texture(t_game *game, char *c, char *line, int i)
{
	char	*tmp;

	tmp = &line[i + 3];
	while (*tmp == ' ')
		tmp++;
	if (tmp[0] == 0)
		return (1);
	if (copy_texture(game, c, tmp))
		return (1);
	if (copy_texture2(game, c, tmp))
		return (1);
	return (0);
}

int	s_tex(t_game *game, char *line, char *c)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], c, 3) == 0)
	{
		if (take_texture(game, c, line, i))
			return (1);
	}
	return (0);
}
