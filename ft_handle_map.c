/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:33:43 by rabustam          #+#    #+#             */
/*   Updated: 2022/08/16 16:31:04 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_map_rows(t_data *game, char *file);
void	ft_set_stats(t_data *game, char *tmp);
void	ft_get_map_width(t_data *game, char *tmp);
void	ft_write_map(t_data *game, char *tmp);
void	ft_free_map(t_data *game);

void	ft_count_map_rows(t_data *game, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rows++;
		free(line);
	}
	game->map.height = rows;
	close(fd);
}

void	ft_set_stats(t_data *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'P')
		{
			if (game->map.player == 0)
				game->map.player++;
			else
				tmp[i] = '0';
		}
		if (tmp[i] == 'T')
			game->map.trap++;
		if (tmp[i] == 'E')
			game->map.exit++;
		if (tmp[i] == 'C')
			game->map.collectible++;
		i++;
	}
}

void	ft_get_map_width(t_data *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n')
	{
		game->map.width++;
		i++;
	}
}

void	ft_write_map(t_data *game, char *tmp)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	game->map.map[game->map.height] = NULL;
	if (!game->map.map)
		return ;
	while (i < game->map.height)
	{
		game->map.map[i] = ft_substr(tmp, start, game->map.width);
		i++;
		start += game->map.width + 1;
	}
}

void	ft_free_map(t_data *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
}
