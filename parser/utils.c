/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 13:00:51 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	check_color(int n)
{
	if (n >= 0 && n <= 255)
		return (0);
	return (1);
}

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	bad_chr(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == 0)
		return (0);
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "C", 1) || !ft_strncmp(str, "F", 1))
		return (0);
	return (1);
}

int	check_one(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '1')
		return (1);
	return (0);
}

int	check_min_max(t_game *game, char c, char **mat)
{
	if (check_color(ft_atoi(mat[0])) || check_color(ft_atoi(mat[1]))
		|| check_color(ft_atoi(mat[2])))
		return (1);
	if (c == 'C')
	{
		if (game->tex.ceilling[0] != -1)
			return (1);
		game->tex.ceilling[0] = ft_atoi(mat[0]);
		game->tex.ceilling[1] = ft_atoi(mat[1]);
		game->tex.ceilling[2] = ft_atoi(mat[2]);
	}
	if (c == 'F')
	{
		if (game->tex.floor[0] != -1)
			return (1);
		game->tex.floor[0] = ft_atoi(mat[0]);
		game->tex.floor[1] = ft_atoi(mat[1]);
		game->tex.floor[2] = ft_atoi(mat[2]);
	}
	return (0);
}
