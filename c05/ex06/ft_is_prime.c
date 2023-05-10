/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:53:38 by sryou             #+#    #+#             */
/*   Updated: 2022/02/12 11:28:31 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
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
