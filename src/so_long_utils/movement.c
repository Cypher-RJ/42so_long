#include "../../inc/so_long.h"

static void	player_img_update(char key, t_win *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/Steve_B.xpm", &game->img_width, &game->img_height);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/Steve_F.xpm", &game->img_width, &game->img_height);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/Steve_L.xpm", &game->img_width, &game->img_height);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/Steve_R.xpm", &game->img_width, &game->img_height);
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
