/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:40:49 by rcesar-d          #+#    #+#             */
/*   Updated: 2025/02/06 10:40:56 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <stdbool.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	char	**map;
	char	**mapcopy;
	int		n_vc;
	int		n_ve;
	int		n_c;
	int		n_e;
	int		n_p;
	int		moves;
	int		finish;
	int		map_width;
	int		map_height;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		x_pos;
	int		y_pos;
}				t_win;

int		draw_game(t_win *game);
int		check_map(t_win *game);
int		ft_close(t_win *game);
int		check_win(t_win *game);
char	**map_read(char *path, t_win *game);
void	init_game(t_win *game);
void	gameplay(t_win *game);
void	w_key(t_win *game);
void	s_key(t_win *game);
void	a_key(t_win *game);
void	d_key(t_win *game);
void	free_map(char **map);
void	print_error(char *str, t_win *game);
void	print_win(t_win *game);
void	get_win_size(t_win *game);

#endif
