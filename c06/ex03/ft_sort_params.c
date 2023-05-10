/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:34:22 by sryou             #+#    #+#             */
/*   Updated: 2022/02/12 11:34:24 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_newline(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	str_cmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort_arr(char **idx_min, char **end)
{
	char	**idx;

	while (idx_min < end)
	{
		idx = idx_min + 1;
		while (idx < end)
		{
			if (str_cmp(*idx, *idx_min) < 0)
				swap(idx, idx_min);
			idx++;
		}
		idx_min++;
	}
}

int	main(int argc, char *argv[])
{
	int	idx;

	sort_arr(argv + 1, argv + argc);
	idx = 1;
	while (idx < argc)
	{
		ft_putchar_newline(argv[idx]);
		idx++;
	}
	return (0);
}
