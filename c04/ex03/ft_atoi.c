/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:56:12 by sryou             #+#    #+#             */
/*   Updated: 2022/02/10 09:00:51 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	str_to_int(char *str, int *mkint)
{
	int	tempint;

	while ('0' <= *str && *str <= '9')
	{
		tempint = *str - '0';
		*mkint = *mkint * 10 + tempint;
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	is_nega;
	int	mkint;

	is_nega = 0;
	str = check_str(str, &is_nega);
	mkint = 0;
	str_to_int(str, &mkint);
	if (is_nega)
		return (-mkint);
	else
		return (mkint);
}
