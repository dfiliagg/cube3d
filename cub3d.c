/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/07/26 16:32:24 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	(void) game;
	printf("%d\n", keycode);
	if (keycode == 65307)
		exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_parse	parse;
	int		i;
	char	**map;

	parse.NO_path = 0;
	parse.SO_path = 0;
	parse.EA_path = 0;
	parse.WE_path = 0;
	i = 0;
	while (i < 3)
	{
		parse.C_rgb[i] = -1;
		parse.F_rgb[i] = -1;
		i++;
	}
	if (argc != 2)
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	else
	{
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window (game.mlx, 1920, 1080, "CUB3D");
		map = ft_read_map(&game, argv[1], &parse);
		if (!map)
			exit(1);
		if (!parse.NO_path || !parse.SO_path
			|| !parse.EA_path || !parse.WE_path)
		{
			printf("Error: missing textures path\n");
			return (1);
		}
		game.no.img = mlx_xpm_file_to_image(game.mlx, parse.NO_path, &game.no.w,
				&game.no.h);
		game.so.img = mlx_xpm_file_to_image(game.mlx, parse.SO_path, &game.so.w,
				&game.so.h);
		game.ea.img = mlx_xpm_file_to_image(game.mlx, parse.EA_path, &game.ea.w,
				&game.ea.h);
		game.we.img = mlx_xpm_file_to_image(game.mlx, parse.WE_path, &game.we.w,
				&game.we.h);
		if (game.no.img == 0 || game.so.img == 0 || game.ea.img == 0
			|| game.we.img == 0)
		{
			printf("Error: invalid textures path\n");
			return (1);
		}
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
