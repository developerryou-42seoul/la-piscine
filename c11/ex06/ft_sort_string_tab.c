/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:17:30 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:47:11 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int	len;
	int	idx;
	int	cmp_idx;

	len = 0;
	while (tab[len] != 0)
		len++;
	idx = 0;
	while (idx < len)
	{
		cmp_idx = 0;
		while (cmp_idx < len - 1 - idx)
		{
			if (ft_strcmp(tab[cmp_idx], tab[cmp_idx + 1]) > 0)
				ft_swap(tab + cmp_idx, tab + cmp_idx + 1);
			cmp_idx++;
		}
		idx++;
	}
}
