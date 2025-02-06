/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:41:58 by rcesar-d          #+#    #+#             */
/*   Updated: 2025/02/06 10:41:59 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	events(int keycode, t_win *game)
{
	if (keycode == XK_a || keycode == XK_Left)
	{
		game->x_pos -= 1;
		a_key(game);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		game->x_pos += 1;
		d_key(game);
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->y_pos -= 1;
		w_key(game);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		game->y_pos += 1;
		s_key(game);
	}
}

static int	ft_keycode(int keycode, t_win *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You din't finish the game :(\n");
		ft_close(game);
	}
	else if (!game->finish)
		events(keycode, game);
	return (0);
}

void	gameplay(t_win *game)
{
	mlx_hook(game->win, 2, 1L << 0, ft_keycode, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
}
