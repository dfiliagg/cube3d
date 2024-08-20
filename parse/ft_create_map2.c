/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	ft_check_textures(char *str)
{
	if (!ft_strncmp(str, "NO", 3))
		return (1);
	if (!ft_strncmp(str, "SO", 3))
		return (1);
	if (!ft_strncmp(str, "EA", 3))
		return (1);
	if (!ft_strncmp(str, "WE", 3))
		return (1);
	if (!ft_strncmp(str, "C", 2))
		return (1);
	if (!ft_strncmp(str, "F", 2))
		return (1);
	return (0);
}

void	ft_free_c_f(char *str, char **path, char **c_f)
{
	free_str(&str);
	free_mat(&path);
	free_mat(&c_f);
}

void	ft_parse_c_f(char *line, t_game *game)
{
	char	*str;
	char	*str2;
	char	**path;
	char	**c_f;

	c_f = 0;
	str = ft_strtrim(line, " ");
	path = ft_split(str, ' ');
	str2 = str;
	if (ft_check_textures(path[0]))
	{
		if (str[0] == 'F')
		{
			str = &str[1];
			c_f = ft_split(str, ',');
			if (check_all_num(c_f, 3) != 0)
			{
				write(2, "errore\n", 7);
				//free
				exit(1);
			}
			game->tex.floor[0] = ft_atoi(c_f[0]);
			game->tex.floor[1] = ft_atoi(c_f[1]);
			game->tex.floor[2] = ft_atoi(c_f[2]);
		}
		else if (str[0] == 'C')
		{
			str = &str[1];
			c_f = ft_split(str, ',');
			if (check_all_num(c_f, 3) != 0)
			{
				write(2, "errore\n", 7);
				//free
				exit(1);
			}
			game->tex.ceilling[0] = ft_atoi(c_f[0]);
			game->tex.ceilling[1] = ft_atoi(c_f[1]);
			game->tex.ceilling[2] = ft_atoi(c_f[2]);
		}
	}
	str = str2;
	ft_free_c_f(str, path, c_f);
}

#include <stdio.h>

void	ft_parse_textures(char *line, t_game *game)
{
	char	*str;
	char	**path;

	str = 0;
	path = 0;
	str = ft_strtrim(line, " ");
	path = ft_split(str, ' ');
	if (ft_check_textures(path[0]))
	{
		if (ft_strlen(path[1]) > 0)
			path[1][ft_strlen(path[1]) - 1] = '\0';
		if (!ft_strncmp(path[0], "NO", 3))
		{
			if (access(path[1], R_OK))
			{
				write(2,  "Error: incorrect textures\n", 26);
				exit(1);
			}
			game->tex.nord = ft_strdup(path[1]);
		}
		else if (!ft_strncmp(path[0], "SO", 3))
		{
			if (access(path[1], R_OK))
			{
				write(2,  "Error: incorrect textures\n", 26);
				exit(1);
			}
			game->tex.sud = ft_strdup(path[1]);
		}
		else if (!ft_strncmp(path[0], "WE", 3))
		{
			if (access(path[1], R_OK))
			{
				write(2,  "Error: incorrect textures\n", 26);
				exit(1);
			}
			game->tex.ovest = ft_strdup(path[1]);
		}
		else if (!ft_strncmp(path[0], "EA", 3))
		{
			if (access(path[1], R_OK))
			{
				write(2,  "Error: incorrect textures\n", 26);
				exit(1);
			}
			game->tex.est = ft_strdup(path[1]);
		}
	}
	free_str(&str);
	free_mat(&path);
}

int	ft_check_map2(char **map)
{
	int	y;
	int	x;

	y = 1;
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
