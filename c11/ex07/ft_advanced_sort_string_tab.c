/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:06 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:48:19 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	_ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
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
			if (cmp(tab[cmp_idx], tab[cmp_idx + 1]) > 0)
				_ft_swap(tab + cmp_idx, tab + cmp_idx + 1);
			cmp_idx++;
		}
		idx++;
	}
}
