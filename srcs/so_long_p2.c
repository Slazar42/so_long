/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:11:36 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:32:43 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_and_scep(t_game *g)
{
	norm_('i', g, &g->i, &g->j);
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j] != '\n' && g->map[g->i][g->j] != '\0')
		{
			if (!(g->map[0][g->j] == '1' && g->map[g->size - 1][g->j] == '1'
				&& g->map[g->i][0] == '1' && g->map[g->i][g->len - 2] == '1'))
				handling_errors(1);
			if (g->map[g->i][g->j] == 'P')
				norm_('p', g, &g->i, &g->j);
			if (g->map[g->i][g->j] == 'C')
				norm_('c', g, &g->i, &g->j);
			if (g->map[g->i][g->j] == 'E')
				norm_('e', g, &g->i, &g->j);
			if (g->map[g->i][g->j] != 'C' && g->map[g->i][g->j] != 'E'
				&& g->map[g->i][g->j] != '1' && g->map[g->i][g->j] != 'P'
				&& g->map[g->i][g->j] != '0')
				handling_errors(5);
			g->j++;
		}
		g->i++;
	}
	check_cep(g);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (*s1)
	{
		*ptr = *s1;
		s1++;
		ptr++;
	}
	*ptr = '\0';
	return (ptr - len);
}

void	map_copy(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->map_copy = (char **)malloc(g->size * sizeof(char *));
	while (g->map[i])
	{
		g->map_copy[i] = ft_strdup(g->map[i]);
		i++;
	}
}

void	reading_map_part2(t_game *g)
{
	g->map = malloc(g->size * sizeof(char *));
	if (!g->map)
		return ;
	g->size = 0;
	g->len = 0;
	while (1)
	{
		g->map[g->size] = get_next_line(g->map_fd);
		if (g->map[g->size] == NULL)
			break ;
		if (g->map[g->size][0] == '\n' && g->map[g->size][1] == '\0')
			handling_errors(10);
		g->size++;
	}
	g->len = ft_strlen(g->map[0]);
	check_and_scep(g);
	map_copy(g);
	valid_map(g, g->px, g->py);
	if (g->col > 0 || g->exit > 0)
		handling_errors(6);
}

void	reading_map(t_game *g)
{
	char	*ll;

	g->map_fd = open(g->map_name, O_RDWR);
	g->size = 0;
	while (1)
	{
		ll = get_next_line(g->map_fd);
		if (ll)
			free(ll);
		else
			break ;
		g->size++;
	}
	close(g->map_fd);
	g->map_fd = open(g->map_name, O_RDWR);
	if (g->map_fd < 0)
		handling_errors(9);
	reading_map_part2(g);
}
