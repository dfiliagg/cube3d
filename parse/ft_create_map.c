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

void	util_r_m(t_read_map *r)
{
	printf("Error: invalid map\n");
	free_str(&r->line);
	free_mat(&r->map);
	exit(1);
}

void	init_rm(t_read_map *r, char *argv, t_game *game)
{
	r->i = 0;
	r->j = 0;
	r->fd = open(argv, O_RDONLY);
	count_line(game, r->fd, argv);
	close(r->fd);
	r->fd = open(argv, O_RDONLY);
	r->line = get_next_line(r->fd);
}

void	util_r_m2(t_read_map *r)
{
	r->i = 0;
	r->map = malloc(sizeof(char *) * 100);
	while (r->line && r->line[0] != '\0')
	{
		if (*r->line != '\0')
			r->map[r->i++] = r->line;
		else
			free(r->line);
		r->line = get_next_line(r->fd);
	}
	free_str(&r->line);
	r->map[r->i] = 0;
	close(r->fd);
}

void	util_r_m4(t_read_map *r, t_game *game)
{
	ft_parse_textures(r->line, game);
	ft_parse_c_f(r->line, game);
}

char	**ft_read_map(t_game *game, char *argv)
{
	t_read_map	r;

	init_rm(&r, argv, game);
	while (r.line != 0)
	{
		util_r_m4(&r, game);
		if (*r.line == '\0' || *r.line == '\n')
			;
		else if (r.j < 6)
			r.j++;
		else
			break ;
		free(r.line);
		r.line = get_next_line(r.fd);
	}
	util_r_m2(&r);
	if (ft_check_map(r.map) && ft_check_map2(r.map) && ft_check_rgb(game))
		return (r.map);
	return (util_r_m(&r), NULL);
}
