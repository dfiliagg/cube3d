/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 10:50:08 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	free_matrix(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free (map);
	map = 0;
	return (1);
}

int	free_texture(t_game *game)
{
	if (game->tex.nord)
		free(game->tex.nord);
	if (game->tex.sud)
		free(game->tex.sud);
	if (game->tex.est)
		free(game->tex.est);
	if (game->tex.ovest)
		free(game->tex.ovest);
	game->tex.nord = 0;
	game->tex.sud = 0;
	game->tex.ovest = 0;
	game->tex.est = 0;
	return (1);
}

int	free_map(t_map map)
{
	if (!map.map)
		return (1);
	free_matrix (map.map);
	return (1);
}

int	free_game(t_game *game)
{
	free_texture(game);
	free_map(game->map);
	game->map.map = NULL;
	exit(0);
}
