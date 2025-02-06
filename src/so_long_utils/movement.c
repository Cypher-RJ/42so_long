/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:41:52 by rcesar-d          #+#    #+#             */
/*   Updated: 2025/02/06 10:41:53 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	player_img_update(char key, t_win *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/B_Player.xpm", &game->img_width, &game->img_height);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/F_Player.xpm", &game->img_width, &game->img_height);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/L_Player.xpm", &game->img_width, &game->img_height);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/R_Player.xpm", &game->img_width, &game->img_height);
}

void	w_key(t_win *game)
{
	player_img_update('w', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		game->map[game->y_pos + 1][game->x_pos] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || \
		game->map[game->y_pos][game->x_pos] == 'E')
		game->y_pos += 1;
	else
	{
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos + 1][game->x_pos] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	s_key(t_win *game)
{
	player_img_update('s', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		game->map[game->y_pos - 1][game->x_pos] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || \
		game->map[game->y_pos][game->x_pos] == 'E')
		game->y_pos -= 1;
	else
	{
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos - 1][game->x_pos] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	a_key(t_win *game)
{
	player_img_update('a', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		game->map[game->y_pos][game->x_pos + 1] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || \
		game->map[game->y_pos][game->x_pos] == 'E')
		game->x_pos += 1;
	else
	{
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos][game->x_pos + 1] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	d_key(t_win *game)
{
	player_img_update('d', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		game->map[game->y_pos][game->x_pos - 1] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || \
		game->map[game->y_pos][game->x_pos] == 'E')
		game->x_pos -= 1;
	else
	{
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos][game->x_pos - 1] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}
