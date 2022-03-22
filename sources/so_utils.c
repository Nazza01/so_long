/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:31:31 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 14:52:52 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Exits the game using destroy window and free alongside exit
*/
int	sl_exit(t_game *game)
{
	int	line;

	ft_printf("\n\tExiting Game\n");
	line = 0;
	if (game->draw.win)
		mlx_destroy_window(game->draw.mlx, game->draw.win);
	free(game->draw.mlx);
	while (line < game->row - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

/*
Shorthand mlx_put_image_to_window
*/
void	sl_pi2w(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->draw.mlx, game->draw.win, img, x, y);
}

/*
Checks the map name using ft_strnstr and ft_strlen
*/
void	check_map_name(char *mapname, t_game *game)
{
	if (!(ft_strnstr(mapname, ".ber", ft_strlen(mapname))))
	{
		ft_printf("Error please make sure the map is in .ber format!\n");
		sl_exit(game);
	}
}
