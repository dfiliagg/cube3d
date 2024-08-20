/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	draw_sky_floor(t_game *game)
{
	t_point	begin;
	t_point	end;
	int		y;

	begin.x = 0;
	end.x = WIDTH;
	y = -1;
	while (++y < (HEIGHT / 2))
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, create_trgb(0,
				game->tex.ceilling[0], game->tex.ceilling[1],
				game->tex.ceilling[2]));
	}
	y -= 1;
	while (++y < HEIGHT)
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->data, begin, end, create_trgb(0,
				game->tex.floor[0], game->tex.floor[1], game->tex.floor[2]));
	}
}

void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_point		start;

	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			start.x = x * 11;
			start.y = y * 11;
			if (game->map.map[y][x] == '1')
				draw_square(&game->minimap.map, start, 11, 0x00FFFFFF);
			else
				draw_square(&game->minimap.map, start, 11, 0x004A474E);
		}
	}
	start.x = (game->player.pos.x * 11) - 2.5;
	start.y = (game->player.pos.y * 11) - 2.5;
	draw_square(&game->minimap.map, start, 5, 0x00FF0000);
}

int	draw_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_minimap(game);
	draw_sky_floor(game);
	raycaster_flat(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->data.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->minimap.map.img, 0, 0);
	update_inputs(game);
	usleep(8000);
	return (0);
}
