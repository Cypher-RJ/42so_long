#include "../../inc/so_long.h"

static int	check_rectangle(t_win *game)
{
	int	len;

	len = 1;
	if (!game->map)
		return (0);
	get_win_size(game);
	while (game->map[len])
	{
		if (ft_strlen(game->map[len]) != ft_strlen(game->map[0]))
			return (0);
		len++;
	}
	return (1);
}

static int	check_close(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x] != '\0' || map[y - 1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	x = ft_strlen(map[y]);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_pce(t_win *game)
{
	int	y;
	int	x;

	game->n_c = 0;
	game->n_e = 0;
	game->n_p = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
				game->n_p++;
			else if (game->map[y][x] == 'C')
				game->n_c++;
			else if (game->map[y][x] == 'E')
				game->n_e++;
			x++;
		}
		y++;
	}
	if (game->n_p != 1 || game->n_e != 1 || game->n_c == 0)
		return (0);
	return (1);
}

static int	check_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C' && \
				map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_win *game)
{
	if (check_rectangle(game) && check_close(game->map) && check_pce(game) && \
		check_valid(game->map) && check_win(game))
		return (1);
	else if (!check_rectangle(game))
		print_error("Map is not rectangle.", game);
	else if (!check_close(game->map))
		print_error("Map is not closed.", game);
	else if (!check_pce(game))
		print_error("PCE not valid.", game);
	else if (!check_valid(game->map))
		print_error("Invalid map. Only P, C, E, 1, 0 allowed.", game);
	else if (!check_win(game))
		print_error("The map is not winable", game);
	return (0);
}
