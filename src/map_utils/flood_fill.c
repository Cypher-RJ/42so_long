#include "../../inc/so_long.h"

static void	flood_fill(t_win *game, int y, int x, char visit)
{
	get_win_size(game);
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width \
		|| game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == visit)
		return ;
	if (game->mapcopy[y][x] == 'C')
		game->mapcopy[y][x] = '0';
	if (game->mapcopy[y][x] == 'E')
	{
		game->mapcopy[y][x] = visit;
		return ;
	}
	game->mapcopy[y][x] = visit;
	flood_fill(game, y + 1, x, visit);
	flood_fill(game, y - 1, x, visit);
	flood_fill(game, y, x + 1, visit);
	flood_fill(game, y, x - 1, visit);
}

static void	ft_pl_pos(t_win *game, int *pl_y, int *pl_x)
{
	int	y;
	int	x;

	y = 0;
	while (game->mapcopy[y])
	{
		x = 0;
		while (game->mapcopy[y][x])
		{
			if (game->mapcopy[y][x] == 'P')
			{
				*pl_y = y;
				*pl_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void	check_ce(t_win *game)
{
	int	y;
	int	x;

	game->n_vc = 0;
	game->n_ve = 0;
	y = 0;
	while (game->mapcopy[y])
	{
		x = 0;
		while (game->mapcopy[y][x])
		{
			if (game->mapcopy[y][x] == 'C')
				game->n_vc++;
			if (game->mapcopy[y][x] == 'E')
				game->n_ve++;
			x++;
		}
		y++;
	}
}

static void	put_exit_wall(t_win *game, int *y, int *x)
{
	int	col;
	int	row;

	row = 0;
	while (game->mapcopy[row])
	{
		col = 0;
		while (game->mapcopy[row][col])
		{
			if (game->mapcopy[row][col] == 'E')
			{
				game->mapcopy[row][col] = '1';
				*y = row;
				*x = col;
				break ;
			}
			col++;
		}
		row++;
	}
}

int	check_win(t_win *game)
{
	int	pl_x;
	int	pl_y;
	int	x;
	int	y;

	pl_x = 0;
	pl_y = 0;
	x = 0;
	y = 0;
	ft_pl_pos(game, &pl_y, &pl_x);
	put_exit_wall(game, &y, &x);
	flood_fill(game, pl_y, pl_x, 'X');
	game->mapcopy[y][x] = 'E';
	flood_fill(game, pl_y, pl_x, 'V');
	check_ce(game);
	if (game->n_vc != 0 || game->n_ve != 0)
		return (0);
	return (1);
}
