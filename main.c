/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/11 10:08:57 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map.map = 0;
	if (parsing(argc, argv, &game) == 1)
	{
		printf("Error in .cub file\n");
		return (1);
	}
	check_last_z(&game);
	if (check_letters(game.map.map))
		return (free_game(&game), 1);
	check_first_wall(&game);
	init(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, input_on_press, (void *)&game);
	mlx_hook(game.mlx_win, 3, 1L << 1, input_on_release, (void *)&game);
	mlx_loop_hook(game.mlx, draw_frame, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
