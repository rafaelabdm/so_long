/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:11:25 by rabustam          #+#    #+#             */
/*   Updated: 2022/08/16 15:17:36 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_press_x(t_data *game);
int		ft_key_press(int key, t_data *game);
void	ft_game_over(t_data *game);
void	ft_check_winner(t_data *game);

void	ft_check_winner(t_data *game)
{
	if (game->map.collectible == 0)
	{
		write(1, "Congratilations! You win!\n", 26);
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_game_over(t_data *game)
{
	write(1, "Fiuka got caught! You lose.\n", 28);
	ft_clear_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_FAILURE);
}

int	ft_key_press(int key, t_data *game)
{
	if (key == ESC)
	{
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_data *game)
{
	ft_key_press(ESC, game);
	return (0);
}
