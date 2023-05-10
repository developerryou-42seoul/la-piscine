/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:38:20 by sryou             #+#    #+#             */
/*   Updated: 2022/02/03 10:44:34 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_num_pair(int num1, int num2)
{
	char	second;
	char	first;

	second = num1 / 10 + '0';
	first = num1 % 10 + '0';
	write(1, &second, 1);
	write(1, &first, 1);
	write(1, " ", 1);
	second = num2 / 10 + '0';
	first = num2 % 10 + '0';
	write(1, &second, 1);
	write(1, &first, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			write_num_pair(num1, num2);
			if (num1 != 98)
			{
				write(1, ", ", 2);
			}
			num2++;
		}
		num1++;
		num2 = num1 + 1;
	}
}
