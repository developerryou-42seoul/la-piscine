/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:21:59 by sryou             #+#    #+#             */
/*   Updated: 2022/02/05 10:01:40 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_low(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	return (0);
}	

int	is_up(char c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

void	change_alphabet(char *c, int is_space)
{
	if (is_space && is_low(*c))
	{
		*c = *c - 32;
	}
	else if ((!is_space) && is_up(*c))
	{
		*c = *c + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		is_space;
	char	*idx_address;

	is_space = 1;
	idx_address = str;
	while (*idx_address != '\0')
	{
		if (is_low(*idx_address) || is_up(*idx_address))
		{
			change_alphabet(idx_address, is_space);
		}
		is_space = 1;
		if (is_num(*idx_address) || is_low(*idx_address) || is_up(*idx_address))
		{
			is_space = 0;
		}
		idx_address++;
	}
	return (str);
}
