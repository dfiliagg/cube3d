/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:33 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	check_letters(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == 'N' ||
			map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E'
			|| map[y][x] == ' ' || map[y][x] == 10)
				;
			else
			{
				printf("Error: strange symbols in the map\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_sky_flo(t_game *game)
{
	if (game->tex.ceilling[0] == -1 || game->tex.floor[0] == -1)
	{
		printf("Error\n missing color");
		return (1);
	}
	return (0);
}

int	c_a(char *path)
{
	if (access(path, R_OK))
		return (0);
	return (1);
}

void	r_m_util(t_game *game, int i, char *line, int fd)
{
	game->map.map[i] = 0;
	get_map_hw(game);
	free_string(line);
	close(fd);
}

int	read_map(t_game *game, char *line, int fd)
{
	int	i;
	int	j;

	if (!c_a(game->tex.est) || !c_a(game->tex.ovest) || !c_a(game->tex.sud)
		|| !c_a(game->tex.nord) || check_sky_flo(game))
		return (1);
	game->map.map = malloc(100 * sizeof(char *));
	game->map.map[0] = line;
	i = 1;
	line = get_next_line(fd);
	while (line != 0)
	{
		j = 0;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		while (line[j] == ' ')
			j++;
		if (line[j] == 0)
			break ;
		game->map.map[i++] = line;
		line = get_next_line(fd);
	}
	r_m_util(game, i, line, fd);
	return (0);
}
