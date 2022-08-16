/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:18:09 by rabustam          #+#    #+#             */
/*   Updated: 2022/08/16 15:03:43 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_render(t_data *game);
void	ft_draw_map(t_data *game, int x, int y);
void	ft_open_exit(t_data *game, int pixel);

void	ft_draw_map(t_data *game, int x, int y)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, \
			x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, \
			x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == 'P')
	{
		if (game->moves % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_0, \
			x * PIXEL, y * PIXEL);
		else if (game->moves % 2 == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_1, \
			x * PIXEL, y * PIXEL);
	}
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img.collectible, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->win, game->img.trap, \
			x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, \
			x * PIXEL, y * PIXEL);
}

void	ft_open_exit(t_data *game, int pixel)
{
	mlx_destroy_image(game->mlx, game->img.exit);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Exit.xpm", &pixel, &pixel);
}

int	ft_render(t_data *game)
{
	int		y;
	int		x;
	char	*show;

	y = 0;
	x = 0;
	show = ft_itoa(game->moves);
	if (game->map.collectible == 0)
		ft_open_exit(game, PIXEL);
	while (game->map.map[y] != NULL)
	{
		while (game->map.map[y][x] != '\0')
		{
			ft_draw_map(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(game->mlx, game->win, 3, 12, 0x00000, show);
	free(show);
	return (0);
}
