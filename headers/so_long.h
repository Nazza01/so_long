/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:06:38 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/21 02:47:11 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 32
# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ON_DESTROY 17
# define ON_EXPOSE 12

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

/*		MLX Library		*/
typedef struct s_smlx
{
	void	*grass;
	void	*wall;
	void	*player;
	void	*exit;
	void	*coin;
	void	*mlx;
	void	*win;
}	t_smlx;

/*		Total Counters		*/
typedef struct s_count
{
	int			player;
	int			coins;
	int			exit;
	int			moves;
}	t_count;

/*		Player Position		*/
typedef struct s_pos
{
	int			first;
	int			second;
}	t_pos;

/*		Game Data		*/
typedef struct s_game
{
	t_smlx		draw;
	t_count		count;
	t_pos		player;
	int			fd;
	int			row;
	int			col;
	char		**map;
}	t_game;

/*		Checking Map Functions			*/
void	validate_map_content(t_game *game);
int		wall_check_row(t_game *game);
int		wall_check_column(t_game *game);
void	check_surround_walls(t_game *game);
void	check_char_at(t_game *game, int height, int width);

/*		Keyboard/Controls Functions		*/
int		handle_keyboard_input(int command, t_game *game);
int		validate_move(t_game *game, int col, int row);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

/*		Map Reading Functions			*/
int		read_map_file(t_game *game, char **argv);
int		count_map_col(char *map_line);
int		alloc_tile_map(t_game *game, char *line);

/*		MLX Functions					*/
void	update_graphics(t_game *game);
void	check_place_mlx(t_game *game, char check, int r, int c);
void	assign_img(t_game *game);

/*		Utility Functions 				*/
int		sl_exit(t_game *game);
void	sl_pi2w(t_game *game, void *img, int x, int y);
void	check_map_name(char *mapname, t_game *game);

#endif
