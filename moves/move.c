/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/01 12:10:41 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	input_on_press(int key, t_game *game)
{
	if (key == 0 || key == 'a')
		game->player.mov_dir.y = -1;
	else if (key == 1 || key == 's')
		game->player.mov_dir.x = 1;
	else if (key == 2 || key == 'd')
		game->player.mov_dir.y = 1;
	else if (key == 13 || key == 'w')
		game->player.mov_dir.x = -1;
	else if (key == 123 || key == 65361)
		game->player.rot_dir = -1;
	else if (key == 124 || key == 65363)
		game->player.rot_dir = 1;
	else if (key == 65307)
		free_game(game);
	return (0);
}

int	input_on_release(int key, t_game *game)
{
	if (key == 13 || key == 1 || key == 'w' || key == 's')
		game->player.mov_dir.x = 0;
	else if (key == 0 || key == 2 || key == 'a' || key == 'd')
		game->player.mov_dir.y = 0;
	else if (key == 123 || key == 124 || key == 65363 || key == 65361)
		game->player.rot_dir = 0;
	return (0);
}
