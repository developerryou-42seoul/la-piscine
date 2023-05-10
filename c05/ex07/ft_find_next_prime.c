/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:54:07 by sryou             #+#    #+#             */
/*   Updated: 2022/02/13 10:11:36 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_ft_is_prime(int nb)
{
	long long int	div;

	if (nb <= 1)
		return (0);
	div = 2;
	while (div * div <= (long long int)nb)
	{
		if ((long long int)nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 2;
	while (!_ft_is_prime(nb))
		nb++;
	return (nb);
}
