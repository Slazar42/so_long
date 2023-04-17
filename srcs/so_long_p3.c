/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_p3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:11:45 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:33:03 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *c)
{
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
}

void	valid_map(t_game *g, int x, int y)
{
	if (g->col == 0 && g->exit == 0)
		return ;
	if (g->map_copy[x][y] == '1')
		return ;
	if (g->map_copy[x][y] == 'C')
		g->col--;
	else if (g->map_copy[x][y] == 'E')
		g->exit--;
	g->map_copy[x][y] = '1';
	valid_map(g, x + 1, y);
	valid_map(g, x - 1, y);
	valid_map(g, x, y + 1);
	valid_map(g, x, y - 1);
}

void	handling_errors(int num_error)
{
	if (num_error == 1)
		ft_putstr("\033[91mError, Map is not surronded by 1 or not rectangle.\n");
	else if (num_error == 2)
		ft_putstr("\033[91mError, Collectible must be one at least.\n");
	else if (num_error == 3)
		ft_putstr("\033[91mError, Exit must be one.\n");
	else if (num_error == 4)
		ft_putstr("\033[91mError, Player must be one.\n");
	else if (num_error == 5)
		ft_putstr("\033[91mError, Map must contain 1, E, P, C, 0\n");
	else if (num_error == 6)
		ft_putstr("\033[91mError, Path not valid.\n");
	else if (num_error == 7)
		ft_putstr("\033[91mError, Try :\n./so_long <Map name>.\n");
	else if (num_error == 8)
		ft_putstr("\033[91mError, Map name is not correct.\n");
	else if (num_error == 9)
		ft_putstr("\033[91mError, Map not found.\n");
	else if (num_error == 10)
		ft_putstr("\033[91mError, Empty line in the map.\n");
	else if (num_error == 11)
		ft_putstr("\033[91mError, Map is big than this mac screen 5120*2880.\n");
	else if (num_error == 12)
		ft_putstr("\x1b[93mYou Quit the Game !!.      \n");
	exit(1);
}

void	check_cep(t_game *g)
{
	if (g->col < 1)
		handling_errors(2);
	if (g->exit != 1)
		handling_errors(3);
	if (g->player != 1)
		handling_errors(4);
}

void	norm_(char c, t_game *g, int *i, int *j)
{
	if (c == 'i')
	{
		g->mouves = 1;
		g->col = 0;
		g->col_copy = 0;
		g->exit = 0;
		g->player = 0;
	}
	else if (c == 'p')
	{
		g->player++;
		g->px = *i;
		g->py = *j;
	}
	else if (c == 'e')
	{
		g->exit++;
		g->ex = *i;
		g->ey = *j;
	}
	else if (c == 'c')
	{
		g->col++;
		g->col_copy++;
	}
}
