/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:33 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	check_last_border(t_game *game)
{
	int		i;
	int		last;
	char	**map;

	i = 1;
	last = game->map.height - 2;
	map = game->map.map;
	while (map[last][i + 1] != 0)
	{
		if (map[last][i] == '0')
		{
			if (map[last + 1][i - 1] != '1' || map[last + 1][i + 1] != '1')
			{
				printf("Error\nMap is open\n");
				free_game(game);
			}
		}
		i++;
	}
}

void	check_one_last(t_game *game)
{
	int		i;
	char	**map;

	i = 1;
	map = game->map.map;
	while (map[1][i + 1] != 0)
	{
		if (map[1][i] == '0')
		{
			if (map[0][i - 1] != '1' || map[0][i + 1] != '1')
			{
				printf("Error\nMap is open\n");
				free_game(game);
			}
		}
		i++;
	}
	check_last_border(game);
}

void	check_empty_file(char *s)
{
	if (s == 0)
	{
		printf("Error:\n file is empty\n");
		exit(1);
	}
}

void	fill_space(t_game *game)
{
	char	**map;
	int		i;
	int		j;
	int		x;

	i = game->map.height;
	j = game->map.width;
	map = malloc((i + 1) * sizeof(char *));
	map[i] = 0;
	i = -1;
	while (++i < (int)game->map.height)
	{
		x = -1;
		map[i] = malloc(j + 1);
		while (x < j)
			map[i][++x] = ' ';
		map[i][x] = 0;
		x = -1;
		while (++x < (int)ft_strlen(game->map.map[i]))
			map[i][x] = game->map.map[i][x];
	}
	free_mat(game->map.map);
	game->map.map = map;
}
