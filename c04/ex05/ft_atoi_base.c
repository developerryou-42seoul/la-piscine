/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:56:12 by sryou             #+#    #+#             */
/*   Updated: 2022/02/10 12:39:26 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_invalid(char *base)
{
	int	idx;

	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (1);
		if (!(' ' <= *base && *base <= '~'))
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

char	*check_str(char *str, int *is_nega)
{
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*is_nega = 1 - *is_nega;
		str++;
	}
	return (str);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	is_nega;
	int	mkint;
	int	base_size;

	base_size = ft_strlen(base);
	if (base_size <= 1 || is_invalid(base))
		return (0);
	is_nega = 0;
	str = check_str(str, &is_nega);
	mkint = 0;
	while (basechar_to_int(*str, base, base_size) >= 0)
	{
		mkint = mkint * base_size + basechar_to_int(*str, base, base_size);
		str++;
	}
	if (is_nega)
		return (-mkint);
	else
		return (mkint);
}
