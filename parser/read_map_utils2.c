/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:33 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	check_last_z(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map[++i])
	{
		if (game->map.map[i][ft_strlen(game->map.map[i]) - 1] == '0')
		{
			error(game, "Map is open");
		}
	}
	fill_space(game);
	check_one_last(game);
}
