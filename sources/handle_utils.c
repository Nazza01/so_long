/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:19:46 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 14:21:50 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Determines if the move the player makes is one of the following:
	E	exit
		Checks if the player has collected all the coins. 
			If not, the player doesn't move to the exit tile
	0	empty space
		Makes the empty space the current player space
		Updates the players position as passed through using col and row 
			(determined when the function is called)
		Increments the players move
	C	coin/collectible
		Same as above with the only difference is that the current coin has now
		been collected and decrements the coin counter.
*/
int	validate_move(t_game *game, int col, int row)
{
	if (game->map[row][col] == 'E')
	{
		if (game->count.coins != 0)
			return (0);
		ft_printf("Congrats! You have won!\nThankyou for playing :)");
		sl_exit(game);
	}
	if (game->map[row][col] == '0')
	{
		game->map[row][col] = 'P';
		game->player.first = col;
		game->player.second = row;
		game->count.moves++;
	}
	if (game->map[row][col] == 'C')
	{
		game->map[row][col] = 'P';
		game->player.first = col;
		game->player.second = row;
		game->count.coins--;
		game->count.moves++;
		ft_printf("\tCoin Collected!\n");
		ft_printf("\tCoins remaining: %i\n", game->count.coins);
	}
	return (1);
}

/*
Updates the players' position according to keyboard input.
Re-assigns player.first and player.second for the scope of readability.
Updates the last players' tile to be a 0 as this is now empty space.
Outputs the current move according to the current counter.
*/
int	move_up(t_game *game)
{
	int	up;
	int	down;
	int	valid;

	up = game->player.first;
	down = game->player.second;
	valid = 0;
	down--;
	if (game->map[down][up] == '1')
		return (0);
	valid = validate_move(game, up, down);
	if (!valid)
		return (0);
	game->map[down + 1][up] = '0';
	ft_printf("Total Moves: %i\n", game->count.moves);
	return (1);
}

/*
Updates the players' position according to keyboard input.
Re-assigns player.first and player.second for the scope of readability.
Updates the last players' tile to be a 0 as this is now empty space.
Outputs the current move according to the current counter.
*/
int	move_down(t_game *game)
{
	int	up;
	int	down;
	int	valid;

	up = game->player.first;
	down = game->player.second;
	down++;
	if (game->map[down][up] == '1')
		return (0);
	valid = validate_move(game, up, down);
	if (!valid)
		return (0);
	game->map[down - 1][up] = '0';
	ft_printf("Total Moves: %i\n", game->count.moves);
	return (1);
}

/*
Updates the players' position according to keyboard input.
Re-assigns player.first and player.second for the scope of readability.
Updates the last players' tile to be a 0 as this is now empty space.
Outputs the current move according to the current counter.
*/
int	move_left(t_game *game)
{
	int	left;
	int	right;
	int	valid;

	left = game->player.first;
	right = game->player.second;
	left--;
	if (game->map[right][left] == '1')
		return (0);
	valid = validate_move(game, left, right);
	if (!valid)
		return (0);
	game->map[right][left + 1] = '0';
	ft_printf("Total Moves: %i\n", game->count.moves);
	return (1);
}

/*
Updates the players' position according to keyboard input.
Re-assigns player.first and player.second for the scope of readability.
Updates the last players' tile to be a 0 as this is now empty space.
Outputs the current move according to the current counter.
*/
int	move_right(t_game *game)
{
	int	left;
	int	right;
	int	valid;

	left = game->player.first;
	right = game->player.second;
	left++;
	if (game->map[right][left] == '1')
		return (0);
	valid = validate_move(game, left, right);
	if (!valid)
		return (0);
	game->map[right][left - 1] = '0';
	ft_printf("Total Moves: %i\n", game->count.moves);
	return (1);
}
