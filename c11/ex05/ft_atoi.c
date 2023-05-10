/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:56:12 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:38:21 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

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

int	str_to_int(char *str)
{
	int	mkint;

	mkint = 0;
	while ('0' <= *str && *str <= '9')
	{
		mkint = mkint * 10 + (*str - '0');
		str++;
	}
	return (mkint);
}

int	ft_atoi(char *str)
{
	int	is_nega;
	int	mkint;

	is_nega = 0;
	str = check_str(str, &is_nega);
	mkint = str_to_int(str);
	if (is_nega)
		return (-mkint);
	else
		return (mkint);
}
