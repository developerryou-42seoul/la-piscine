/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:56:55 by sryou             #+#    #+#             */
/*   Updated: 2022/02/10 17:49:42 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	vector_init(int (*vector)[8])
{
	vector[0][0] = 1;
	vector[0][1] = 0;
	vector[0][2] = -1;
	vector[0][3] = -1;
	vector[0][4] = -1;
	vector[0][5] = 0;
	vector[0][6] = 1;
	vector[0][7] = 1;
	vector[1][0] = -1;
	vector[1][1] = -1;
	vector[1][2] = -1;
	vector[1][3] = 0;
	vector[1][4] = 1;
	vector[1][5] = 1;
	vector[1][6] = 1;
	vector[1][7] = 0;
}

void	write_line(int (*map)[10])
{
	int		row;
	int		idx;
	char	c;

	row = 0;
	while (row < 10)
	{
		idx = 0;
		while (idx < 10)
		{
			if (map[row][idx] == 1)
			{
				c = idx + '0';
				write(1, &c, 1);
			}
			idx++;
		}
		row++;
	}
	write(1, "\n", 1);
}

void	putpath(int (*map)[10], int y, int x, int trigger)
{
	int	vector[2][8];
	int	idx_vector;
	int	y_idx;
	int	x_idx;

	map[y][x] += trigger;
	vector_init(vector);
	idx_vector = 0;
	while (idx_vector < 8)
	{
		y_idx = y + vector[0][idx_vector];
		x_idx = x + vector[1][idx_vector];
		while ((0 <= y_idx && y_idx < 10) && (0 <= x_idx && x_idx < 10))
		{
			map[y_idx][x_idx] += trigger;
			y_idx += vector[0][idx_vector];
			x_idx += vector[1][idx_vector];
		}
		idx_vector++;
	}
}

int	recursive(int (*map)[10], int row)
{
	int	idx;
	int	sum;

	if (row == 10)
	{
		write_line(map);
		return (1);
	}
	idx = 0;
	sum = 0;
	while (idx < 10)
	{
		if (map[row][idx] == 0)
		{
			putpath(map, row, idx, 1);
			sum += recursive(map, row + 1);
			putpath(map, row, idx, -1);
		}
		idx++;
	}
	return (sum);
}

int	ft_ten_queens_puzzle(void)
{
	int	map[10][10];
	int	init_idx;

	init_idx = 0;
	while (init_idx < 100)
	{
		(*map)[init_idx] = 0;
		init_idx++;
	}
	return (recursive(map, 0));
}
