#include "../../inc/so_long.h"

static void	init_img(t_win *game)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		"textures/Grass.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/Bedrock.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"textures/Steve_F.xpm", &game->img_width, &game->img_height);
	game->img_colect = mlx_xpm_file_to_image(game->mlx, \
		"textures/Diamond.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		"textures/Chest_closed.xpm", &game->img_width, &game->img_height);
}

void	get_win_size(t_win *game)
{
	int	y;

	game->map_width = ft_strlen(game->map[0]) * 64;
	y = 0;
	while (game->map[y])
		y++;
	game->map_height = y * 64;
	if (game->map_width > game->win_width || \
		game->map_height > game->win_height)
		print_error("Map is too big for the screen.", game);
}

void	init_game(t_win *game)
{
	get_win_size(game);
	game->win = mlx_new_window(game->mlx, game->map_width, \
		game->map_height, "so_long");
	game->moves = 0;
	game->finish = 0;
	init_img(game);
	draw_game(game);
}
