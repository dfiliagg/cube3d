/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:33 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	check_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == ' ')
		{
			if (map[1][i] == '1' || map[1][i] == ' ')
				;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_line(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
		j++;
	j--;
	while (map[j][i])
	{
		if (map[j][i] == '0')
			return (0);
		else if (map[j][i] == ' ')
		{
			if (map[j - 1][i] == '1' || map[j - 1][i] == ' ')
				;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_row(char **map)
{
	if (check_first_line(map) == 0 || check_last_line(map) == 0)
		return (0);
	return (1);
}

int	ft_map_len(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		;
	return (y);
}

int	ft_check_map2(char **map)
{
	int	y;
	int	x;

	y = 1;
	if (check_row(map) == 0)
		return (0);
	while (map[y] && y < ft_map_len(map) - 1)
	{
		x = 1;
		while (map[y][x] && (size_t)x < ft_strlen(map[y]) - 1)
		{
			if (map[y][x] == 32)
			{
				if (map[y - 1][x - 1] == '0' || map[y - 1][x] == '0' ||
					map[y - 1][x + 1] == '0' || map[y][x - 1] == '0' ||
					map[y][x + 1] == '0' || map[y + 1][x - 1] == '0' ||
					map[y + 1][x] == '0' || map[y + 1][x - 1] == '0')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
