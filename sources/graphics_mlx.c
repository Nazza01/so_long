/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:21:05 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 14:58:11 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Uses the shorthand sl_pi2w function to draw each element.
Accepts a character to check against and the position to draw the image to.
If the following are detected:
	C	coin/collectible	Adds a coin to the counter for other functions
	P	mario/player		Updates the players' position accordingly
*/
void	check_place_mlx(t_game *game, char check, int y, int x)
{
	if (check == '0')
		sl_pi2w(game, game->draw.grass, x * TILE, y * TILE);
	else if (check == '1')
		sl_pi2w(game, game->draw.wall, x * TILE, y * TILE);
	else if (check == 'C')
	{
		sl_pi2w(game, game->draw.coin, x * TILE, y * TILE);
		game->count.coins++;
	}
	else if (check == 'E')
		sl_pi2w(game, game->draw.exit, x * TILE, y * TILE);
	else if (check == 'P')
	{
		sl_pi2w(game, game->draw.player, x * TILE, y * TILE);
		game->player.second = y;
		game->player.first = x;
	}
}

/*
Assigns each image according to the files in the img folder.
Uses mlx's xpm_file_to_image function to pull each file into an image.
Mlx will use these to draw each image to the window as needed.
w and h aren't used but are needed for the function to work - they contain the 
size of each picture, as they are already pre-defined in the header under TILE
we do not need them.
*/
void	assign_img(t_game *game)
{
	int	w;
	int	h;

	game->draw.grass = mlx_xpm_file_to_image(game->draw.mlx, "img/grass.XPM", \
			&w, &h);
	game->draw.wall = mlx_xpm_file_to_image(game->draw.mlx, "img/wall.XPM", \
			&w, &h);
	game->draw.player = mlx_xpm_file_to_image(game->draw.mlx, "img/mario.XPM", \
			&w, &h);
	game->draw.exit = mlx_xpm_file_to_image(game->draw.mlx, "img/flag.XPM", \
			&w, &h);
	game->draw.coin = mlx_xpm_file_to_image(game->draw.mlx, "img/coin.XPM", \
			&w, &h);
}

/*
Updates the mlx graphics using the check_place_mlx for each map character.
Uses an iterator to check each character for passing to the function.
*/
void	update_graphics(t_game *game)
{
	int	row_i;
	int	col_i;

	game->count.coins = 0;
	row_i = 0;
	while (row_i < game->row)
	{
		col_i = 0;
		while (game->map[row_i][col_i])
		{
			check_place_mlx(game, game->map[row_i][col_i], row_i, col_i);
			col_i++;
		}
		row_i++;
	}
}
