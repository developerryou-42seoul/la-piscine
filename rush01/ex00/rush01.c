/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:24:12 by sryou             #+#    #+#             */
/*   Updated: 2022/02/13 17:28:15 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	handle_argv(int argc, char **argv)
{
	int	watch_size;

	if (argc != 2)
		return (0);
	watch_size = is_valid_string(argv[1]);
	return (watch_size);
}

void	free_all(int **map, int *watch, int map_size)
{
	int	idx;

	free(watch);
	idx = 0;
	while (idx < map_size)
		free(map[idx++]);
	free(map);
}

int	main(int argc, char **argv)
{
	int	watch_size;
	int	map_size;
	int	*watch;
	int	**map;

	watch_size = handle_argv(argc, argv);
	if (watch_size == 0)
		return (print_error());
	map_size = watch_size / 4;
	watch = init_watch(argv[1], watch_size);
	if (watch == 0)
		return (print_error());
	map = init_map(map_size);
	if (map == 0)
	{
		free(watch);
		return (print_error());
	}
	if (recursive(map, watch, 0, map_size) == 0)
		(void)print_error();
	free_all(map, watch, map_size);
	return (0);
}
