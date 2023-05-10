/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 08:40:34 by sryou             #+#    #+#             */
/*   Updated: 2022/02/03 10:51:22 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_arr(int arr[], int n)
{
	int		idx;
	char	write_buf;

	idx = 0;
	while (idx < n)
	{
		write_buf = arr[idx] + '0';
		write(1, &write_buf, 1);
		idx++;
	}
}

void	recursive(int arr[], int num, int current, int n)
{
	int	idx;

	if (current == n)
	{
		write_arr(arr, n);
		if (arr[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	idx = num;
	while (idx <= 9)
	{
		arr[current] = idx;
		recursive(arr, idx + 1, current + 1, n);
		idx++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	recursive(arr, 0, 0, n);
}
