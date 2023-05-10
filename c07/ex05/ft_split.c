/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:44:14 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 11:57:19 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	if (*str == '\0' && c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	words;
	int	is_word;

	words = 0;
	is_word = 1;
	while (*str)
	{
		if (is_char_in_str(*str, charset))
			is_word = 1;
		else
		{
			if (is_word)
				words++;
			is_word = 0;
		}
		str++;
	}
	return (words);
}

char	*cut_word(char *str, int len)
{
	char	*word;
	int		idx;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	idx = 0;
	while (idx < len)
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr_words;
	int		count_words;
	int		idx;
	int		len;

	count_words = ft_count_words(str, charset);
	arr_words = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (arr_words == 0)
		return (0);
	idx = 0;
	while (idx < count_words)
	{
		len = 0;
		while (is_char_in_str(*str, charset))
			str++;
		while (!is_char_in_str(str[len], charset))
			(len)++;
		arr_words[idx] = cut_word(str, len);
		if (arr_words[idx] == 0)
			return (0);
		idx++;
		str += len;
	}
	arr_words[idx] = 0;
	return (arr_words);
}
