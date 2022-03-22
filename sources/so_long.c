/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:33:05 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 15:01:29 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Only starts/draws the program if argument counter is 2.
If the program does not contain 2 arguments (1: program, 2: map) it will output
an error and return (0);
*/
int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		check_map_name(av[1], &game);
		read_map_file(&game, av);
		check_surround_walls(&game);
		validate_map_content(&game);
		game.draw.mlx = mlx_init();
		game.draw.win = mlx_new_window(game.draw.mlx, game.col * TILE, \
				game.row * TILE, "So Long");
		assign_img(&game);
		update_graphics(&game);
		mlx_key_hook(game.draw.win, handle_keyboard_input, &game);
		mlx_hook(game.draw.win, ON_DESTROY, 0, sl_exit, &game);
		mlx_loop(game.draw.mlx);
	}
	else if (ac != 2)
		ft_printf("Please make sure you have typed a map!\n");
	return (0);
}
