/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:21:57 by rabustam          #+#    #+#             */
/*   Updated: 2022/08/16 15:35:44 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_player_c(t_data *game, int pixel, char dir);
void	ft_change_player(t_data *game, int pixel, char dir);
void	ft_create_images(t_data *game);
void	ft_create_player(t_data *game, int pixel);
void	ft_clear_images(t_data *game);

void	ft_change_player_c(t_data *game, int pixel, char dir)
{
	if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fuika_C0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fuika_C1.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fuika_C2.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fuika_C3.xpm", &pixel, &pixel);
	}
}

void	ft_change_player(t_data *game, int pixel, char dir)
{
	if (game->sock == 1)
		ft_change_player_c(game, pixel, dir);
	else if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fiuka_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fiuka_1.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fiuka_2.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Fiuka_3.xpm", &pixel, &pixel);
	}
}

void	ft_create_images(t_data *game)
{
	int	pixel;

	pixel = PIXEL;
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./sprites/Floor.xpm", \
		&pixel, &pixel);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./sprites/Wall.xpm", \
		&pixel, &pixel);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Sock.xpm", &pixel, &pixel);
	game->img.trap = mlx_xpm_file_to_image(game->mlx, "./sprites/Trap_0.xpm", \
		&pixel, &pixel);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Exit_close.xpm", &pixel, &pixel);
	ft_create_player(game, pixel);
}

void	ft_create_player(t_data *game, int pixel)
{
	game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Fiuka_0.xpm", &pixel, &pixel);
	game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Fiuka_1.xpm", &pixel, &pixel);
}

void	ft_clear_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.player_0);
	mlx_destroy_image(game->mlx, game->img.player_1);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.collectible);
	mlx_destroy_image(game->mlx, game->img.trap);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
	free(game->t_pos.y);
	free(game->t_pos.x);
}
