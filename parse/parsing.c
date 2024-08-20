/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	parsing(int argc, char **argv, t_game *game)
{
	int		i;

	game->tex.est = 0;
	game->tex.nord = 0;
	game->tex.sud = 0;
	game->tex.ovest = 0;
	i = 0;
	while (i < 3)
	{
		game->tex.floor[i] = -1;
		game->tex.ceilling[i] = -1;
		i++;
	}
	if (argc != 2)
		return (printf("Error: invalid arguments\n"), 1);
	else
	{
		game->map.map = ft_read_map(game, argv[1]);
		game->map.width = ft_map_h(game->map.map);
		if (!game->map.map)
			exit(1);
		if (!game->tex.nord || !game->tex.sud
			|| !game->tex.ovest || !game->tex.est)
			return (printf("Error: missing textures path\n"), 1);
	}
	return (0);
}
