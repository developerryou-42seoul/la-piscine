/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:53:22 by sryou             #+#    #+#             */
/*   Updated: 2022/02/12 11:27:12 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int	root;

	root = 0;
	while (root * root <= (long long int)nb)
	{
		if (root * root == (long long int)nb)
			return ((int)root);
		root++;
	}
	return (0);
}
