/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_c_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 13:03:29 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

//cicla la matrice e controlla se sono tutti numeri
int	verify_all_num(char **mat)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	i = -1;
	str = 0;
	while (mat[++i])
	{
		tmp = (char *) mat[i];
		while (*tmp && *tmp == ' ')
			tmp++;
		if (!(*tmp))
			return (1);
		str = ft_strtrim(mat[i], " ");
		j = -1;
		while (str[++j])
			if (str[j] < '0' || str[j] > '9')
				return (free_string(str), 1);
		free_string(str);
	}
	if (i != 3)
		return (write(2, "Error\nThe map must containg 1 player", 37), 1);
	return (0);
}

// conta le virgole e splitta in una matrice
int	take_cf(t_game *game, char c, char *line, int i)
{
	char	*tmp;
	char	**mat;
	int		r;

	tmp = &line[i];
	if (count_char(line, ',') != 2)
		return (1);
	mat = ft_split(tmp, ',');
	if (verify_all_num(mat) != 0)
	{
		free_mat(mat);
		return (1);
	}
	r = check_min_max(game, c, mat);
	free_mat(mat);
	return (r);
}

//controlla se nella linea trova il carattere che ci interessa
int	search_c_f(t_game *game, char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == c)
		if (take_cf(game, c, line, i + 1) == 1)
			return (1);
	return (0);
}

int	read_m_util(char *l, t_game *g)
{
	if (bad_chr(l) || search_c_f(g, l, 'C') || search_c_f(g, l, 'F')
		|| s_tex(g, l, "NO ") || s_tex(g, l, "SO ")
		|| s_tex(g, l, "WE ") || s_tex(g, l, "EA "))
		return (1);
	return (0);
}

//apre il file e cerca tra le linee
int	read_m(t_game *g, char *file)
{
	int		fd;
	char	*l;

	fd = open(file, O_RDONLY);
	if (!fd)
		exit (1);
	l = get_next_line(fd);
	check_empty_file(l);
	while (l != 0)
	{
		l[ft_strlen(l) - 1] = 0;
		if (check_one(l))
		{
			if (read_map(g, l, fd))
				return (free_texture(g), free_string(l), close(fd), 1);
			return (0);
		}
		if (read_m_util(l, g))
			return (free_texture(g), free_string(l), close(fd), 1);
		free_string(l);
		l = get_next_line(fd);
	}
	if (!g->map.map)
		return (error(g, "No Map"), free_game(g), free_string(l), close(fd), 1);
	return (0);
}
