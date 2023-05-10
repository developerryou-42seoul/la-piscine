/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:51:25 by sryou             #+#    #+#             */
/*   Updated: 2022/02/09 12:52:29 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	if (power < 0)
		return (0);
	answer = 1;
	while (power > 0)
	{
		answer = answer * nb;
		power--;
	}
	return (answer);
}
