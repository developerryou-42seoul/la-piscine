/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehwang <hehwang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:00:43 by hehwang           #+#    #+#             */
/*   Updated: 2022/02/12 18:51:21 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function checks numbers of user's arguments if =< 9 upto 1x1 ~ 9x9 */
/* + finally check valid number range */

int	is_numeric(char c)
{
	if ('1' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_one_number(char *str)
{
	if (*str)
	{
		if (is_numeric(*str))
		{
			if (*(str + 1) == ' ' || *(str + 1) == '\0')
				return (1);
		}
	}
	return (0);
}

int	is_valid_range(char *str, int count)
{
	if (count > 36 || count % 4 > 0)
		return (0);
	while (*str)
	{
		if (is_numeric(*str))
		{
			if (*str - '0' > count / 4)
				return (0);
		}
		str++;
	}
	return (1);
}

int	is_valid_string(char *str)
{
	char	*addr;
	int		count;

	addr = str;
	count = 0;
	while (*addr)
	{
		if (is_one_number(addr))
		{
			count++;
			addr++;
			if (*addr != '\0')
				addr++;
		}
		else
			return (0);
	}
	if (is_numeric(*(addr - 1)) && is_valid_range(str, count))
		return (count);
	else
		return (0);
}
