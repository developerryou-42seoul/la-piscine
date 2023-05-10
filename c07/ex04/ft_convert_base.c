/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:41:17 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 18:51:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		make_10base_int(char *nbr, char *base, int base_size);
char	*make_nbase_str(long long nbr, char *base, long long base_size);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	is_invalid(char *base)
{
	int	idx;

	if (ft_strlen(base) <= 1)
		return (1);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (1);
		if (*base == ' ' || ('\t' <= *base && *base <= '\r'))
			return (1);
		idx = 1;
		while (base[idx])
		{
			if (*base == base[idx])
				return (1);
			idx++;
		}
		base++;
	}
	return (0);
}

char	*check_nbr(char *nbr, int *is_nega)
{
	while (*nbr == ' ' || ('\t' <= *nbr && *nbr <= '\r'))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			*is_nega = 1 - *is_nega;
		nbr++;
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	is_nega;
	int	cal_10base;
	int	ibase;
	int	obase;

	if (is_invalid(base_from) || is_invalid(base_to))
		return (0);
	is_nega = 0;
	nbr = check_nbr(nbr, &is_nega);
	ibase = ft_strlen(base_from);
	obase = ft_strlen(base_to);
	cal_10base = make_10base_int(nbr, base_from, ibase);
	if (is_nega)
		cal_10base = -cal_10base;
	return (make_nbase_str((long long)cal_10base, base_to, (long long)obase));
}
