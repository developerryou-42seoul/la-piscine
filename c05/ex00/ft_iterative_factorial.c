/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:39 by sryou             #+#    #+#             */
/*   Updated: 2022/02/12 08:51:41 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	answer;

	if (nb < 0)
		return (0);
	answer = 1;
	while (nb > 0)
	{
		answer = answer * nb;
		nb--;
	}
	return (answer);
}
