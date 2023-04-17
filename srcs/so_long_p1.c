/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:11:15 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:51:50 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ac_checker(int ac, char **av, t_game *g)
{
	int	len;

	g->map_name = av[1];
	len = ft_strlen(g->map_name);
	if (ac != 2)
		handling_errors(7);
	else if (ac == 2)
	{
		if (!(g->map_name[len - 1] == 'r' && g->map_name[len - 2] == 'e'
				&& g->map_name[len - 3] == 'b' && g->map_name[len - 4] == '.'))
			handling_errors(8);
	}
}

void	png_to_texture(t_game *g)
{
	g->texture_wall = mlx_load_png("./imgs/wall1.png");
	g->img_wall = mlx_texture_to_image(g->mlx, g->texture_wall);
	g->texture_player = mlx_load_png("./imgs/player.png");
	g->img_player = mlx_texture_to_image(g->mlx, g->texture_player);
	g->texture_floor = mlx_load_png("./imgs/floor.png");
	g->img_floor = mlx_texture_to_image(g->mlx, g->texture_floor);
	g->texture_fire1 = mlx_load_png("./imgs/fire1.png");
	g->img_fire1 = mlx_texture_to_image(g->mlx, g->texture_fire1);
	g->texture_closed_door = mlx_load_png("./imgs/door1.png");
	g->img_closed_door = mlx_texture_to_image(g->mlx, g->texture_closed_door);
	g->texture_opened_door = mlx_load_png("./imgs/door2.png");
	g->img_opened_door = mlx_texture_to_image(g->mlx, g->texture_opened_door);
}

void	rendring_imgs(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	png_to_texture(g);
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != '\n')
		{
			mlx_image_to_window(g->mlx, g->img_floor, j * 64, i * 64);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->img_wall, j * 64, i * 64);
			else if (g->map[i][j] == 'P')
				mlx_image_to_window(g->mlx, g->img_player, j * 64, i * 64);
			else if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->img_closed_door, j * 64, i * 64);
			else if (g->map[i][j] == 'C')
				mlx_image_to_window(g->mlx, g->img_fire1, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_mini_putnbr(int i)
{
	char	c;

	if (i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_mini_putnbr(i / 10);
		ft_mini_putnbr(i % 10);
	}
}

void	keyfunction(mlx_key_data_t keycode, void *g_ptr)
{
	t_game	*g;

	g = (t_game *)g_ptr;
	if (keycode.key == MLX_KEY_ESCAPE)
		handling_errors(12);
	if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
		&& g->map[g->px + 1][g->py] != '1')
		down_handler(g);
	if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
		&& g->map[g->px - 1][g->py] != '1')
		up_handler(g);
	if ((keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
		&& g->map[g->px][g->py - 1] != '1')
		left_handler(g);
	if ((keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
		&& g->map[g->px][g->py + 1] != '1')
		right_handler(g);
}
