/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_p4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:31:29 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:49:04 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_numbers(int n)
{
	int	c;

	c = 0;
	if (n < 0)
		c = 1;
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	c = count_numbers(n) + 1;
	str = (char *)malloc(c);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str [c - 1] = '\0';
	while (n)
	{
		str[c - 2] = n % 10 + '0';
		n = n / 10;
		c--;
	}
	return (str);
}

void	rendring_imgs_bonus(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	mlx_put_string(g->mlx, "Moves:", 0, 3);
	mlx_put_string(g->mlx, "0", 5, 20);
}
