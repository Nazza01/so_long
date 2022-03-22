/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:20:04 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 13:55:04 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Validates the map contents using check_char_at to make sure the map contains 
the correct characters.
Errors if at least one player, coin or exit isn't found.
*/
void	validate_map_content(t_game *game)
{
	int	row_iter;
	int	col_iter;

	row_iter = 0;
	while (row_iter < game->row - 1)
	{
		col_iter = 0;
		while (col_iter <= game->col)
		{
			check_char_at(game, row_iter, col_iter);
			col_iter++;
		}
		row_iter++;
	}
	if (!(game->count.player == 1 && game->count.coins > 0 && \
			game->count.exit == 1))
	{
		printf("Error, check at least one of these are in the map!\n");
		printf("\tP - player, C - coins, E - exit\n");
		sl_exit(game);
	}
}

/*
Checks a row in the map for 1's to satisfy the rule that maps must contain a wall
on the top and bottom of the map.
*/
int	wall_check_row(t_game *game)
{
	int	col;
	int	index;

	col = game->col;
	index = 0;
	while (index < col)
	{
		if (game->map[0][col] == '1' && game->map[game->row - 1][index] == '1')
			return (0);
		index++;
	}
	return (1);
}

/*
Checks a column in the map for 1's to satisfy the rule that maps must contain a
wall on the left and right sides of the map.
*/
int	wall_check_column(t_game *game)
{
	int	col;
	int	index;

	col = game->col;
	index = 0;
	while (index < game->row)
	{
		if (!(game->map[index][0] == '1' && game->map[index][col - 1] == '1'))
			return (0);
		index++;
	}
	return (1);
}

/*
Checks the surrounding walls using the two above wall checker functions.
If either of these functions fail, the game will print out an error followed by
using the sl_exit function to cleanly free memory and close the game.
*/
void	check_surround_walls(t_game *game)
{
	if (!wall_check_row(game) || !wall_check_column(game))
	{
		ft_printf("Error: Please check the map is surrounded by walls!\n");
		sl_exit(game);
	}
}

/*
Checks for any of the following characters so the map is valid. Incrementing
counters to tally up the map contents ready to be used in the checking functions
when the player picks up a coin and for the exit as the player must collect all
coins before exiting the map.
	0		Empty space
	1		Wall
	C		Coin/Collectible
	E		Flag/Exit
	P		Mario/Player
	\n		Newline				Is valid due to the map ending on a \0 char \n
								indicates more map contents is on the next line
*/
void	check_char_at(t_game *game, int row, int col)
{
	if (game->map[row][col] != '0' && game->map[row][col] != '1' && \
		game->map[row][col] != 'C' && game->map[row][col] != 'E' && \
		game->map[row][col] != 'P' && game->map[row][col] != '\n')
	{
		ft_printf("Error %c is not a valid character!", game->map[row][col]);
		sl_exit(game);
	}
	if (game->map[row][col] == 'C')
			game->count.coins++;
	if (game->map[row][col] == 'P')
			game->count.player++;
	if (game->map[row][col] == 'E')
			game->count.exit++;
}
