/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:16:34 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 18:51:50 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	basechar_to_int(char c, char *base, int base_size)
{
	int	idx;

	idx = 0;
	while (idx < base_size)
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	make_10base_int(char *nbr, char *base, int base_size)
{
	int	mkint;

	mkint = 0;
	while (basechar_to_int(*nbr, base, base_size) >= 0)
	{
		mkint = mkint * base_size + basechar_to_int(*nbr, base, base_size);
		nbr++;
	}
	return (mkint);
}

void	make_nbr_base(long long nbr, char *base, long long base_size, char *str)
{
	if (nbr == 0)
		return ;
	*str = base[nbr % base_size];
	make_nbr_base(nbr / base_size, base, base_size, str - 1);
}

int	find_len_nbr_base(long long nbr, long long base_size)
{
	if (nbr < base_size)
		return (1);
	return (1 + find_len_nbr_base(nbr / base_size, base_size));
}

char	*make_nbase_str(long long nbr, char *base, long long base_size)
{
	char	*nbase_str;
	int		len_str;

	if (nbr < 0)
		len_str = find_len_nbr_base(-nbr, base_size) + 1;
	else
		len_str = find_len_nbr_base(nbr, base_size);
	nbase_str = (char *)malloc(sizeof(char) * (len_str + 1));
	if (nbase_str == 0)
		return (0);
	if (nbr < 0)
	{
		nbase_str[0] = '-';
		make_nbr_base(-nbr, base, base_size, nbase_str + len_str - 1);
	}
	else if (nbr == 0)
		nbase_str[0] = base[0];
	else
		make_nbr_base(nbr, base, base_size, nbase_str + len_str - 1);
	nbase_str[len_str] = 0;
	return (nbase_str);
}
