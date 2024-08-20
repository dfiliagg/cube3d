/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:33 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	get_map_hw(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		i++;
	game->map.height = i;
	i = 0;
	game->map.width = 0;
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) > (size_t)game->map.width)
			game->map.width = ft_strlen(game->map.map[i]);
		i++;
	}
}

void	count_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'W' || game->map.map[i][j] == 'E' )
				count ++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		printf("You can set only one player\n");
		free_game(game);
	}
}

void	fill_one(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] == ' ')
		{
			game->map.map[i][j] = '1';
			j++;
		}
		i++;
	}
	return ;
}

void	check_if_open(t_game *game)
{
	count_player(game);
	if (ft_check_map2(game->map.map) == 0)
	{
		printf("Error\nThe map is open!\n");
		free_game(game);
	}
	fill_one(game);
}

int	check_first_wall(t_game *game)
{
	char	**map;
	int		i;
	char	*str;

	i = -1;
	map = game->map.map;
	while (map[++i])
	{
		str = map[i];
		while (*str == ' ')
			str++;
		if (*str != '1')
			return (printf("Error\n"), free_game(game), 1);
	}
	check_if_open(game);
	return (0);
}
