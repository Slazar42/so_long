/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:32:16 by slazar            #+#    #+#             */
/*   Updated: 2023/04/17 21:52:03 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "/Users/slazar/MLX42/include/MLX42/MLX42.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*my_filter_cut(char *save);
char	*my_filter(char *save);
int		my_strchr(char *str, char c);
char	*my_strjoin(char *save, char *bufer);
int		ft_strlen(char *c);

typedef struct game
{
	int				len;
	char			*map_name;
	int				map_fd;
	char			**map;
	char			**map_copy;
	int				size;
	char			*s;
	int				col_copy;
	int				col;
	int				player;
	int				exit;
	int				px;
	int				py;
	int				ex;
	int				ey;
	int				i;
	int				j;
	void			*mlx;
	int				mouves;
	char			*moves;
	mlx_texture_t	*texture_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture_player;
	mlx_image_t		*img_player;
	mlx_texture_t	*texture_floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*texture_fire1;
	mlx_image_t		*img_fire1;
	mlx_texture_t	*texture_closed_door;
	mlx_image_t		*img_closed_door;
	mlx_texture_t	*texture_opened_door;
	mlx_image_t		*img_opened_door;
}				t_game;

char	*ft_calloc(int count, int size);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ac_checker(int ac, char **av, t_game *g);
void	png_to_texture(t_game *g);
void	rendring_imgs(t_game *g);
void	rendring_imgs_bonus(t_game *g);
void	ft_mini_putnbr(int i);
void	keyfunction(mlx_key_data_t keycode, void *g_ptr);
void	check_and_scep(t_game *g);
char	*ft_strdup(char *s1);
void	map_copy(t_game *g);
void	reading_map_part2(t_game *g);
void	left_handler(t_game *g);
void	right_handler(t_game *g);
void	down_handler(t_game *g);
void	up_handler(t_game *g);
void	reading_map(t_game *g);
void	ft_putstr(char *c);
void	valid_map(t_game *g, int x, int y);
void	handling_errors(int num_error);
void	check_cep(t_game *g);
void	norm_(char c, t_game *g, int *i, int *j);
char	*ft_itoa(int n);

#endif