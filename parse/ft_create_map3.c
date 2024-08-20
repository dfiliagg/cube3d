/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	init_c_m(t_check_map *c_map)
{
	c_map->pos_counter = 0;
	c_map->y = 0;
	c_map->str = 0;
}

int	last_check(t_check_map *c)
{
	if (c->pos_counter != 1)
		return (0);
	c->x = 0;
	while (c->str && c->str[c->x])
	{
		if (c->str[c->x] != '1')
			return (0);
		c->x++;
	}
	return (1);
}

char	**ft_check_map(char **map)
{
	t_check_map	c;

	init_c_m(&c);
	while (map && map[c.y])
	{
		free_str(&c.str);
		c.str = ft_strtrim(map[c.y], " \n");
		c.x = 0;
		while (c.str && c.str[c.x])
		{
			if (c.y == 0 && c.str[c.x] != '1')
				return (0);
			if ((c.x == 0 && c.str[c.x] != '1') || (c.x == ft_strlen(c.str) - 1
					&& c.str[c.x] != '1'))
				return (0);
			if (c.str[c.x] == 'N' || c.str[c.x] == 'W' || c.str[c.x] == 'E'
				|| c.str[c.x] == 'S')
				c.pos_counter++;
			c.x++;
		}
		c.y++;
	}
	if (last_check(&c) == 0)
		return (0);
	return (free_str(&c.str), map);
}

int	ft_check_rgb(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->tex.floor[i] < 0
			|| game->tex.floor[i] > 255 || game->tex.ceilling[i] < 0
			|| game->tex.ceilling[i] > 255)
			return (0);
		i++;
	}
	return (1);
}
