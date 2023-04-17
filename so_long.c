/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:32:18 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:32:08 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_handler(t_game *g)
{
	ft_mini_putnbr(g->mouves);
	ft_putstr(" : Number of movements.\r");
	mlx_image_to_window(g->mlx, g->img_floor, g->py * 64, g->px * 64);
	g->mouves++;
	if (g->col_copy)
		mlx_image_to_window(g->mlx, g->img_closed_door, g->ey * 64, g->ex * 64);
	else
		mlx_image_to_window(g->mlx, g->img_opened_door, g->ey * 64, g->ex * 64);
	g->py += 1;
	if (g->map[g->px][g->py] == 'C')
	{
		g->col_copy--;
		g->map[g->px][g->py] = '0';
	}
	if (g->px == g->ex && g->py == g->ey && g->col_copy == 0)
	{
		ft_putstr("\033[32mGood job, you WIN !!.      \n");
		exit(1);
	}
	mlx_image_to_window(g->mlx, g->img_player, g->py * 64, g->px * 64);
}

void	left_handler(t_game *g)
{
	ft_mini_putnbr(g->mouves);
	ft_putstr(" : Number of movements.\r");
	g->mouves++;
	mlx_image_to_window(g->mlx, g->img_floor, g->py * 64, g->px * 64);
	if (g->col_copy)
		mlx_image_to_window(g->mlx, g->img_closed_door, g->ey * 64, g->ex * 64);
	else
		mlx_image_to_window(g->mlx, g->img_opened_door, g->ey * 64, g->ex * 64);
	g->py -= 1;
	if (g->map[g->px][g->py] == 'C')
	{
		g->col_copy--;
		g->map[g->px][g->py] = '0';
	}
	if (g->px == g->ex && g->py == g->ey && g->col_copy == 0)
	{
		ft_putstr("\033[32mGood job, you WIN !!.      \n");
		exit(1);
	}
	mlx_image_to_window(g->mlx, g->img_player, g->py * 64, g->px * 64);
}

void	up_handler(t_game *g)
{
	ft_mini_putnbr(g->mouves);
	ft_putstr(" : Number of movements.\r");
	mlx_image_to_window(g->mlx, g->img_floor, g->py * 64, g->px * 64);
	g->mouves++;
	if (g->col_copy)
		mlx_image_to_window(g->mlx, g->img_closed_door, g->ey * 64, g->ex * 64);
	else
		mlx_image_to_window(g->mlx, g->img_opened_door, g->ey * 64, g->ex * 64);
	g->px -= 1;
	if (g->map[g->px][g->py] == 'C')
	{
		g->col_copy--;
		g->map[g->px][g->py] = '0';
	}
	if (g->px == g->ex && g->py == g->ey && g->col_copy == 0)
	{
		ft_putstr("\033[32mGood job, you WIN !!.      \n");
		exit(1);
	}
	mlx_image_to_window(g->mlx, g->img_player, g->py * 64, g->px * 64);
}

void	down_handler(t_game *g)
{
	ft_mini_putnbr(g->mouves);
	ft_putstr(" : Number of movements.\r");
	mlx_image_to_window(g->mlx, g->img_floor, g->py * 64, g->px * 64);
	g->mouves++;
	if (g->col_copy)
		mlx_image_to_window(g->mlx, g->img_closed_door, g->ey * 64, g->ex * 64);
	else
		mlx_image_to_window(g->mlx, g->img_opened_door, g->ey * 64, g->ex * 64);
	g->px += 1;
	if (g->map[g->px][g->py] == 'C')
	{
		g->col_copy--;
		g->map[g->px][g->py] = '0';
	}
	if (g->px == g->ex && g->py == g->ey && g->col_copy == 0)
	{
		ft_putstr("\033[32mGood job, you WIN !!.      \n");
		exit(1);
	}
	mlx_image_to_window(g->mlx, g->img_player, g->py * 64, g->px * 64);
}

int	main(int ac, char **av)
{
	t_game	g;

	ac_checker(ac, av, &g);
	reading_map(&g);
	if ((g.len - 1) * 64 > 5120 / 2 || g.size * 64 > 2880 / 2)
		handling_errors(11);
	g.mlx = mlx_init(64 * (g.len - 1), 64 * g.size, "So_long", 0);
	rendring_imgs(&g);
	mlx_key_hook(g.mlx, &keyfunction, &g);
	mlx_loop(g.mlx);
}
