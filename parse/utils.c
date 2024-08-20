/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:48:11 by adi-fort          #+#    #+#             */
/*   Updated: 2023/07/25 12:51:32 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	free_str(char	**str)
{
	if (str)
		free(*str);
	*str = NULL;
}

void	free_mat(char	***mat)
{
	int	i;

	i = 0;
	while (*mat && (*mat)[i])
	{
		free_str(&((*mat)[i]));
		i++;
	}
	free(*mat);
	*mat = NULL;
}

int	ft_map_len(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		;
	return (y);
}

int	ft_map_h(char **map)
{
	int	y;

	y = -1;
	while (map[0][++y])
		;
	return (y);
}

int	count_line(t_game *game, int fd, char *path)
{
	char	*str;
	int		counter;

	counter = 0;
	str = get_next_line(fd);
	while (str)
	{
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	game->map.height = counter - get_map_line(path) + 1;
	return (counter);
}

int	get_map_line(char *path)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		i++;
		if (str[0] == ' ' || ft_isdigit(str[0]))
		{
			free(str);
			close(fd);
			return (i);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}
