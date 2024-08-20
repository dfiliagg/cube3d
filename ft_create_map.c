/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:18:47 by adi-fort          #+#    #+#             */
/*   Updated: 2023/07/26 16:33:51 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_parse_c_f(char *line, t_parse *parse)
{
	char	*str;
	char	**path;
	char	**c_f;	

	c_f = 0;
	str = 0;
	path = 0;
	str = ft_strtrim(line, " ");
	path = ft_split(str, ' ');
	if (ft_check_textures(path[0]))
	{
		if (str[0] == 'F')
		{
			c_f = ft_split(str, ',');
			parse->F_rgb[0] = ft_atoi(c_f[0]);
			parse->F_rgb[1] = ft_atoi(c_f[1]);
			parse->F_rgb[2] = ft_atoi(c_f[2]);
		}
		else if (str[0] == 'C')
		{
			c_f = ft_split(str, ',');
			parse->C_rgb[0] = ft_atoi(c_f[0]);
			parse->C_rgb[1] = ft_atoi(c_f[1]);
			parse->C_rgb[2] = ft_atoi(c_f[2]);
		}
	}
	free_str(&str);
	free_mat(&path);
	free_mat(&c_f);
}

void	ft_parse_textures(char *line, t_parse *parse)
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
			parse->NO_path = ft_strdup(path[1]);
		else if (!ft_strncmp(path[0], "SO", 3))
			parse->SO_path = ft_strdup(path[1]);
		else if (!ft_strncmp(path[0], "WE", 3))
			parse->WE_path = ft_strdup(path[1]);
		else if (!ft_strncmp(path[0], "EA", 3))
			parse->EA_path = ft_strdup(path[1]);
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

char	**ft_check_map(char **map)
{
	int		y;
	size_t	x;
	char	*str;
	int		pos_counter;

	pos_counter = 0;
	y = 0;
	str = 0;
	while (map && map[y])
	{
		free_str(&str);
		str = ft_strtrim(map[y], " \n");
		x = 0;
		while (str && str[x])
		{
			if (y == 0 && str[x] != '1')
				return (0);
			if ((x == 0 && str[x] != '1') || (x == ft_strlen(str) - 1 && str[x]
					!= '1'))
				return (0);
			if (str[x] == 'N' || str[x] == 'W' || str[x] == 'E'
				|| str[x] == 'S')
				pos_counter++;
			x++;
		}
		y++;
	}
	if (pos_counter != 1)
		return (0);
	x = 0;
	while (str && str[x])
	{
		if (str[x] != '1')
			return (0);
		x++;
	}
	free_str(&str);
	return (map);
}

int	ft_check_rgb(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (parse->F_rgb[i] < 0 || parse->F_rgb[i] > 255 || parse->C_rgb[i] < 0
			|| parse->C_rgb[i] > 255) 
			return (0);
		i++;
	}
	return (1);
}

char	**ft_read_map(t_game *game, char *argv, t_parse *parse)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**map;

	(void)game;
	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		ft_parse_textures(line, parse);
		ft_parse_c_f(line, parse);
		if (*line == '\0' || *line == '\n')
			;
		else if (j < 6)
			j++;
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	map = malloc(sizeof(char *) * 100);
	while (line && line[0] != '\0') 
	{
		if (*line != '\0')
		{
			map[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	free_str(&line);
	map[i] = 0;
	close(fd);
	if (ft_check_map(map) && ft_check_map2(map) && ft_check_rgb(parse))
		return (map);
	else
	{
		printf("Error: invalid map\n");
		free_str(&line);
		free_mat(&map);
		exit(1);
	}
}
