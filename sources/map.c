/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:20:19 by Nathanael         #+#    #+#             */
/*   Updated: 2022/03/20 14:37:48 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Counts up and returns the amount of columns in a map line.
We know the map format contains a line of some form like so: XXXXXXXXXXX
Where X is some valid character, so we know at the end of this string will be
a null terminating character '\0', so we add up from 0 to the end.
Once we encounter a new line we want to subtract it from the count as this isnt
technically drawn but is present in the map as the file contains it.
*/
int	count_map_col(char *map_line)
{
	int	cols;

	cols = 0;
	while (map_line[cols] != '\0')
		cols++;
	if (map_line[cols - 1] == '\n')
		cols--;
	return (cols);
}

/*
Uses malloc to allocate an array of of the file assigning a temporary map to re-
assign back so the games' map contains the lines of the file.
*/
int	alloc_tile_map(t_game *game, char *line)
{
	char	**temp_map;
	int		index;

	if (!line)
		return (0);
	index = 0;
	game->row++;
	temp_map = malloc(sizeof(char *) * (game->row + 1));
	temp_map[game->row] = NULL;
	while (index < game->row - 1)
	{
		temp_map[index] = game->map[index];
		index++;
	}
	temp_map[index] = line;
	if (game->map)
		free(game->map);
	game->map = temp_map;
	return (1);
}

/*
Reads the file using the passed argument av (from main) to read the map line by
line using get_next_line and checks for the final line using the alloc_tile_map
function.
Also checks if the map doesn't contain anything as this was an issue with non
-valid maps being empty.
Starts the map column calculator using the first line of the map.
*/
int	read_map_file(t_game *game, char **av)
{
	char	*readmap;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!alloc_tile_map(game, readmap))
			break ;
	}
	close (game->fd);
	if (game->map == NULL)
	{
		ft_printf("Map doesn't contain anything!");
		sl_exit(game);
	}
	game->col = count_map_col(game->map[0]);
	return (1);
}
