/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:19:56 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 14:27:45 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Checks the keyboard input against the below numbers. Updates graphics using mlx
if a valid move/key is hit.
Keyboard key	Associated Number
	ESC					53
	UP					13
	DOWN				1
	LEFT				0
	RIGHT				2
*/
int	handle_keyboard_input(int command, t_game *game)
{
	int	valid_move;

	valid_move = 0;
	if (command == ESC)
		sl_exit(game);
	if (command == UP)
		valid_move = move_up(game);
	if (command == DOWN)
		valid_move = move_down(game);
	if (command == LEFT)
		valid_move = move_left(game);
	if (command == RIGHT)
		valid_move = move_right(game);
	if (valid_move)
		update_graphics(game);
	return (1);
}
