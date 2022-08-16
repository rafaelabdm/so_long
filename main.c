/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:16:58 by rabustam          #+#    #+#             */
/*   Updated: 2022/08/16 15:40:46 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		write(1, "Error\nInvalid number of arguments.\n", 35);
		return (0);
	}
	if (ft_check_error(&game, argv[1]) < 0)
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL, \
		game.map.height * PIXEL, "Fiuka Socks!");
	ft_create_images(&game);
	mlx_loop_hook(game.mlx, &ft_trap_anim, &game);
	mlx_expose_hook(game.win, &ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	mlx_loop(game.mlx);
}
