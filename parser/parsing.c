/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 12:50:46 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

//inizializza le variabili

void	init_parsing(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		game->tex.floor[i] = -1;
		game->tex.ceilling[i] = -1;
		i++;
	}
	game->tex.est = 0;
	game->tex.nord = 0;
	game->tex.sud = 0;
	game->tex.ovest = 0;
}

//controlla se il file è .cub 

void	check_cub(char *str)
{
	int		i;
	char	*str2;

	i = ft_strlen(str);
	str2 = &str[i - 4];
	if (ft_strncmp((const char *)str2, ".cub", 4) != 0)
	{
		write(2, "Error: need .cub file\n", 23);
		exit(1);
	}
}

//controlla se il file è accessibile

int	read_cub(t_game *game, char *file)
{
	if (!read_m(game, file))
		return (0);
	return (1);
}

//funzione principale parsing

int	parsing(int argc, char **argv, t_game *game)
{
	init_parsing(game);
	if (argc != 2)
		return (printf("Error: invalid arguments\n"), 1);
	else
	{
		check_cub(argv[1]);
		if (access(argv[1], R_OK))
		{
			write(2, "Error: Cannot open map file!\n", 30);
			exit(1);
		}
		if (read_cub(game, argv[1]) != 0)
			return (1);
	}
	return (0);
}
